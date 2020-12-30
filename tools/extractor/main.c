#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "puff.h"
#include "fread_csv_line.h"

#ifdef _WIN32
	#include <windows.h>
	#define MAX_THREADS 32
#elif __APPLE__
	#include <sys/param.h>
	#include <sys/sysctl.h>
	#define MAX_THREADS 32
#else
	#include <unistd.h>
	#ifdef __linux__
		#define MAX_THREADS 32
	#else
		#define MAX_THREADS 1
	#endif
#endif

#define CLAMP_VAL(value, min, max) (((value) < (min)) ? (min) : (((value) > (max)) ? (max) : ((value) < (min)) ? (min) : (value)))
#define MBTOBYTES(megs) (megs*0x100000)
#define LINE "__________________________________________________________________"

#define MIN_ROM_SIZE MBTOBYTES(12) /* minimum ROM filesize supported (12MB) */
#define MAX_FILENAME 256 /* max filename supported */
#define GE_1172_HEADER_LENGTH 2 /* header length of GE 1172 zip */

unsigned char *rom_buf;
unsigned char tmp_buf[MAX_THREADS][MBTOBYTES(2)] = {0}; /* holds our input/output for gzip inflate (max output file supported 2MB) */
pthread_t puff_threads[MAX_THREADS];
unsigned long int counted = 0, success_thread[MAX_THREADS] = {0}, failed_thread[MAX_THREADS] = {0};

struct pthread_arg
{
	unsigned long int offset, size;
	char *name;
	int compress, thread_id, ready;
};

typedef struct pthread_arg arg_thread;

void *extract_thread(void *arg)
{
	/************************/
	arg_thread *thread_arg = (arg_thread *)arg;
	int compress, thread_id, puff_return;
	unsigned long offset, size, out_size;
	char name[MAX_FILENAME];
	FILE *output;
	/************************/

	memcpy(name, thread_arg->name, MAX_FILENAME);
	offset = thread_arg->offset;
	compress = thread_arg->compress;
	size = thread_arg->size;
	thread_id = thread_arg->thread_id;
	printf("\n  Extracting %s %s, %lu bytes...", compress ? "compressed" : "uncompressed", name, size);
	thread_arg->ready = 1;

	output = fopen(name, "wb");
	if(output == NULL)
	{
		printf("\n  Error: Could not output file %s", name);
		failed_thread[thread_id]++;
		goto error_thread_output;
	}
	if(compress) /* unzip */
	{
		puff_return = puff(tmp_buf[thread_id], (unsigned long)MBTOBYTES(2), &rom_buf[offset + GE_1172_HEADER_LENGTH], size, &out_size);
		if(puff_return != 0)
		{
			switch(puff_return)
			{
				case   2: printf("\n\n  Error: Could not uncompress file %s\n  Available inflate data did not terminate\n", name); break;
				case   1: printf("\n\n  Error: Could not uncompress file %s\n  Output space exhausted before completing inflate\n", name); break;
				case  -1: printf("\n\n  Error: Could not uncompress file %s\n  Invalid block type (type == 3)\n", name); break;
				case  -2: printf("\n\n  Error: Could not uncompress file %s\n  Stored block length did not match one's complement\n", name); break;
				case  -3: printf("\n\n  Error: Could not uncompress file %s\n  Dynamic block code description: too many length or distance codes\n", name); break;
				case  -4: printf("\n\n  Error: Could not uncompress file %s\n  Dynamic block code description: code lengths codes incomplete\n", name); break;
				case  -5: printf("\n\n  Error: Could not uncompress file %s\n  Dynamic block code description: repeat lengths with no first length\n", name); break;
				case  -6: printf("\n\n  Error: Could not uncompress file %s\n  Dynamic block code description: repeat more than specified lengths\n", name); break;
				case  -7: printf("\n\n  Error: Could not uncompress file %s\n  Dynamic block code description: invalid literal/length code lengths\n", name); break;
				case  -8: printf("\n\n  Error: Could not uncompress file %s\n  Dynamic block code description: invalid distance code lengths\n", name); break;
				case  -9: printf("\n\n  Error: Could not uncompress file %s\n  Dynamic block code description: missing end-of-block code\n", name); break;
				case -10: printf("\n\n  Error: Could not uncompress file %s\n  Invalid literal/length or distance code in fixed or dynamic block\n", name); break;
				case -11: printf("\n\n  Error: Could not uncompress file %s\n  Distance is too far back in fixed or dynamic block\n", name); break;
				 default: printf("\n\n  Error: Could not uncompress file %s\n  Unknown error\n", name); break;
			}
			failed_thread[thread_id]++;
			goto error_thread_unzip;
		}
		fwrite(tmp_buf[thread_id], out_size, 1, output);
	}
	else /* uncompressed */
	{
		fwrite(&rom_buf[offset], size, 1, output);
	}
	success_thread[thread_id]++;

error_thread_unzip:
	fclose(output);
error_thread_output:
	return NULL;
}

int detect_threads(void)
{
#ifdef WIN32
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	return sysinfo.dwNumberOfProcessors;
#elif __APPLE__
	int nm[2];
	size_t len = 4;
	uint32_t count;

	nm[0] = CTL_HW; nm[1] = HW_AVAILCPU;
	sysctl(nm, 2, &count, &len, NULL, 0);

	if(count < 1)
	{
		nm[1] = HW_NCPU;
		sysctl(nm, 2, &count, &len, NULL, 0);
		if(count < 1)
		{
			count = 1;
		}
	}
	return count;
#elif __linux__
	#if defined (_SC_NPROCESSORS_ONLN)
		return sysconf(_SC_NPROCESSORS_ONLN);
	#elif defined (_SC_NPROC_ONLN)
		return sysconf(_SC_NPROC_ONLN);
	#else
		return 1;
	#endif
#else
	return 1;
#endif
}

void extract_files(FILE *csvfile, const int max_threads)
{
	/************************/
	int cur_line_entry = 0, max_line_entry = 0;
	int eof = 0, index, cur_thread = 0, check_threads = 0;
	char *csv_buf, cur_line;
	unsigned long int offset, size;
	int compress, extract;
	char name[MAX_FILENAME] = {'\0'};
	volatile arg_thread thread_arg;
	/************************/

	/* get max line entry in csv file (required for allocation) */
	while(fread(&cur_line, 1, 1, csvfile))
	{
		if(cur_line == '\n')
		{
			if(cur_line_entry > max_line_entry)
				max_line_entry = cur_line_entry;
			cur_line_entry = 0;
			continue;
		}
		cur_line_entry++;
	}
	if(fseek(csvfile, 0, SEEK_SET) != 0)
	{
		printf("\n  Error: Aborted, could not set to beginning of csv file");
		return;
	}

	if(!fread_csv_alloc(max_line_entry))
	{
		printf("\n  Error: Aborted, could not allocate memory for csv file");
		return;
	}
	while(!eof)
	{
		csv_buf = fread_csv_line(csvfile, &eof);
		if(csv_buf == NULL)
		{
			printf("\n  Error: Aborted, could not read csv line");
			break;
		}

		for(index = 0; index < max_line_entry; index++) /* replace commas with new line characters for sscanf */
		{
			if(csv_buf[index] == ',')
				csv_buf[index] = '\n';
		}
		if(sscanf(csv_buf, "%lu\n%lu\n%s\n%d\n%d", &offset, &size, name, &compress, &extract) != 5) /* error or reached end of csv file, abort */
			break;
		counted++;
		if(extract != 1)
			continue;

		if(check_threads)
		{
			if(pthread_join(puff_threads[cur_thread], NULL) != 0)
			{
				printf("\n  Error: Aborted, could not create thread %d", cur_thread);
				break;
			}
		}
		thread_arg.ready = 0;
		thread_arg.name = name;
		thread_arg.size = size;
		thread_arg.offset = offset;
		thread_arg.compress = !(!compress);
		thread_arg.thread_id = (short)cur_thread;
		pthread_create(&puff_threads[cur_thread], NULL, extract_thread, (void *)&thread_arg);
		for(;;) /* wait for thread to finish copy arguments */
		{
			if(thread_arg.ready)
			{
				break;
			}
		}

		cur_thread++;
		if(cur_thread >= max_threads)
		{
			cur_thread = 0;
			check_threads = 1;
		}
	}
	fread_csv_free();

	cur_thread = 0;
	while(cur_thread < max_threads) /* wait for thread to finish task */
	{
		if(pthread_join(puff_threads[cur_thread], NULL) != 0)
		{
			continue;
		}
		cur_thread++;
	}
}

int main(int argc, char **argv)
{
	/************************/
	FILE *romfile, *csvfile;
	long int filesize;
	int threads_total, index;
	unsigned long success_total = 0, failed_total = 0;
	/************************/

	/* set threads total */
	threads_total = CLAMP_VAL(detect_threads(), 1, MAX_THREADS);

	printf("\n  GoldenEye 007 Extractor\n%s\n", LINE);
	if(argc != 3) /* no file provided or too many arguments */
	{
		printf("\n  About: Extract GoldenEye 007 files\n\n  Syntax: %s \"input ROM\" \"input csv file\"\n  Multithread Mode: %sabled", argv[0], threads_total > 1 ? "En" : "Dis");
		goto exit;
	}

	/* load ROM from argument */
	romfile = fopen(argv[1], "rb");
	if(romfile == NULL)
	{
		printf("\n  Error: Aborted, ROM cannot be opened");
		goto exit;
	}
	if(fseek(romfile, 0, SEEK_END) != 0)
	{
		printf("\n  Error: Aborted, could not find end to ROM file");
		goto error_rom;
	}

	/* get ROM filesize */
	filesize = ftell(romfile);
	if(filesize == -1)
	{
		printf("\n  Error: Aborted, could not find length to ROM file");
		goto error_rom;
	}
	if(filesize < MIN_ROM_SIZE) /* if ROM filesize is under supported filesize, abort */
	{
		printf("\n  Error: Aborted, ROM is invalid");
		goto error_rom;
	}
	if(fseek(romfile, 0, SEEK_SET) != 0)
	{
		printf("\n  Error: Aborted, could not find beginning of ROM file");
		goto error_rom;
	}
	printf("\n  Input ROM: %s", argv[1]);

	/* load csv file from argument */
	csvfile = fopen(argv[2], "rb");
	if(csvfile == NULL)
	{
		printf("\n  Error: Aborted, csv file cannot be opened");
		goto error_rom;
	}

	/* read ROM to file buffer */
	rom_buf = (unsigned char *)malloc(filesize);
	if(rom_buf == NULL)
	{
		printf("\n  Error: Aborted, not enough memory to load ROM");
		goto error_csv;
	}
	fread(rom_buf, filesize, 1, romfile);

	extract_files(csvfile, threads_total);

	for(index = 0; index < threads_total; index++)
	{
		success_total += success_thread[index];
		failed_total += failed_thread[index];
	}
	printf("\n\n  Total Files: %lu\n\n  Extracted: %lu\n  Skipped: %lu", counted, success_total, counted - success_total);
	if(failed_total)
		printf("\n  Failed: %lu", failed_total);

	free(rom_buf);
error_csv:
	fclose(csvfile);
error_rom:
	fclose(romfile);
exit:
	printf("\n%s\n", LINE);
	return 0;
}
