#include <stdio.h>
#include <stdlib.h>
#include "objectives.h"

#define LINE "__________________________________________________________________"

#define PERCENTF(val, val_max) (((float)val / (float)val_max) * 100.f)
#define CLAMP_VAL(value, min, max) (((value) < (min)) ? (min) : (((value) > (max)) ? (max) : ((value) < (min)) ? (min) : (value)))

enum PROGRAM_ARGUMENTS
{
	PROGRAM_NAME = 0,
	SRC_DIR,
	SRC_DIR_MAX,
	GAME_DIR,
	GAME_DIR_MAX,
	INFLATE_DIR,
	INFLATE_DIR_MAX,
	LIBULTRA_DIR,
	LIBULTRA_DIR_MAX,
	DECOMPILED_WORDS,
	DECOMPILED_WORDS_MAX,
	DECOMPILED_FILES,
	DECOMPILED_FILES_MAX,
	HTML_OUTPUT,
	LAST_MODIFIED_FILE,
	LOG_LEVEL,
	ARGS_MAX
};

enum VERBOSITY_LOGGING
{
	LOG_MIN = 0,
	LOG_DEF,
	LOG_MAX
};

int total_objectives(void)
{
	/************************/
	int tmp_mis = 0;
	int tmp_obj = OBJ_A;
	int max_objs = 0;
	/************************/

	for(;;)
	{
		if(missions[tmp_mis].obj[tmp_obj][LINE1] == NULL) /* reached end of mission's objectives, check next mission */
		{
			if(missions[tmp_mis + 1].obj[OBJ_A][LINE1] == NULL) /* reached end of struct, stop counting */
			{
				break;
			}
			tmp_mis++;
			tmp_obj = OBJ_A;
		}
		tmp_obj++;
		max_objs++;
	}
	return max_objs;
}

void calc_mission_and_objective(int *cur_mis, int *cur_obj, int decomp_progress)
{
	/************************/
	int max_objs = 0;
	/************************/

	for(;;)
	{
		if(missions[*cur_mis].obj[*cur_obj][LINE1] == NULL) /* reached end of mission's objectives, check next mission */
		{
			if(missions[*cur_mis + 1].obj[OBJ_A][LINE1] == NULL) /* reached end of struct, stop counting */
			{
				break;
			}
			*cur_mis += 1;
			*cur_obj = OBJ_A;
		}
		*cur_obj += 1;
		max_objs += 1;
		if(max_objs >= decomp_progress)
		{
			break;
		}
	}
}

int max_objectives(const int cur_mis)
{
	/************************/
	int cur_obj = OBJ_A;
	/************************/

	for(;;)
	{
		if(missions[cur_mis].obj[cur_obj][LINE1] == NULL) /* reached end of mission's objectives, break */
		{
			break;
		}
		cur_obj++;
	}
	return cur_obj;
}

int main(int argc, char **argv)
{
	/************************/
	long int src_dir, src_dir_max;
	long int game_dir, game_dir_max;
	long int inflate_dir, inflate_dir_max;
	long int libultra_dir, libultra_dir_max;
	long int decompiled_words, decompiled_words_max;
	long int decompiled_files, decompiled_files_max;
	int cur_mis = 0, cur_obj = OBJ_A;
	int cur_mis_objs_max = 0, max_objs = 0;
	int tmp_obj, cur_line = 0;
	int last_modified_file_arg_active = 0;
	int verbosity_level = LOG_DEF;
	float total_complete, obj_remaining;
	FILE *html;
	/************************/

	/* read logging level */
	if(argc == ARGS_MAX)
	{
		verbosity_level = CLAMP_VAL(atoi(argv[LOG_LEVEL]), 0, 2);
	}
	if(verbosity_level != LOG_MIN)
	{
		printf("\n  GoldenEye 007 Decompiled Statistics Generator\n%s\n", LINE);
	}
	if(argc != ARGS_MAX) /* incorrect number of arguments */
	{
		printf("\n  About: Generate decompiled statistics website\n\n  Syntax: %s src max game max inflate max libultra max decompiled_words max_words decompiled_files all_files html_output last_modified_file verbosity_level (0-2)\n\n  Note: Each dir's statistic must be followed with the total words for the dir.\n  Example: 1481 15854 12641 232276 564 1312 556 20330 15242 269772 49 336 ./index.html \"src/game/bond.c\" 1", argv[PROGRAM_NAME]);
		goto exit;
	}

	/* read arguments */
	src_dir = atol(argv[SRC_DIR]), src_dir_max = atol(argv[SRC_DIR_MAX]);
	game_dir = atol(argv[GAME_DIR]), game_dir_max = atol(argv[GAME_DIR_MAX]);
	inflate_dir = atol(argv[INFLATE_DIR]), inflate_dir_max = atol(argv[INFLATE_DIR_MAX]);
	libultra_dir = atol(argv[LIBULTRA_DIR]), libultra_dir_max = atol(argv[LIBULTRA_DIR_MAX]);
	decompiled_words = atol(argv[DECOMPILED_WORDS]), decompiled_words_max = atol(argv[DECOMPILED_WORDS_MAX]);
	decompiled_files = atol(argv[DECOMPILED_FILES]), decompiled_files_max = atol(argv[DECOMPILED_FILES_MAX]);
	if(src_dir > src_dir_max)
	{
		printf("\n  Error: Aborted, src larger than src max argument");
		goto exit;
	}
	if(game_dir > game_dir_max)
	{
		printf("\n  Error: Aborted, game larger than game max argument");
		goto exit;
	}
	if(inflate_dir > inflate_dir_max)
	{
		printf("\n  Error: Aborted, inflate larger than inflate max argument");
		goto exit;
	}
	if(libultra_dir > libultra_dir_max)
	{
		printf("\n  Error: Aborted, libultra larger than libultra max argument");
		goto exit;
	}
	if(decompiled_words > decompiled_words_max)
	{
		printf("\n  Error: Aborted, decompiled words larger than total words argument");
		goto exit;
	}
	if(decompiled_files > decompiled_files_max)
	{
		printf("\n  Error: Aborted, decompiled files larger than total files argument");
		goto exit;
	}
	if(src_dir < 0 || src_dir_max < 0 || game_dir < 0 || game_dir_max < 0 || inflate_dir < 0 || inflate_dir_max < 0 || libultra_dir < 0 || libultra_dir_max < 0 || decompiled_words < 0 || decompiled_words_max < 0|| decompiled_files < 0 || decompiled_files_max < 0)
	{
		printf("\n  Error: Aborted, detected negative arguments (invalid or overflow)");
		goto exit;
	}
	last_modified_file_arg_active = (argv[LAST_MODIFIED_FILE] != NULL);

	/* print all arguments */
	if(verbosity_level == LOG_MAX)
	{
		printf("\n  src_dir:\t\t%ld / %ld", src_dir, src_dir_max);
		printf("\n  game_dir:\t\t%ld / %ld", game_dir, game_dir_max);
		printf("\n  inflate_dir:\t\t%ld / %ld", inflate_dir, inflate_dir_max);
		printf("\n  libultra_dir:\t\t%ld / %ld", libultra_dir, libultra_dir_max);
		printf("\n  decompiled_words:\t%ld / %ld", decompiled_words, decompiled_words_max);
		printf("\n  decompiled_files:\t%ld / %ld", decompiled_files, decompiled_files_max);
		printf("\n  last_modified_file:\t%s\n%s\n", last_modified_file_arg_active ? argv[LAST_MODIFIED_FILE] : "NULL", LINE);
	}

	html = fopen(argv[HTML_OUTPUT], "ab");
	if(html == NULL)
	{
		printf("\n  Error: Aborted, %s cannot be opened", argv[HTML_OUTPUT]);
		goto exit;
	}

	max_objs = total_objectives();
	total_complete = ((float)decompiled_words / (float)decompiled_words_max) * (float)max_objs;
	obj_remaining = total_complete - (float)((int)total_complete);
	calc_mission_and_objective(&cur_mis, &cur_obj, (int)total_complete);
	cur_mis_objs_max = max_objectives(cur_mis);

	fprintf(html, "<text x=\"363\" y=\"648\">%s</text>\n", missions[cur_mis].diff);
	fprintf(html, "<text x=\"363\" y=\"754\">%s</text>\n", missions[cur_mis].title);
	fprintf(html, "<text x=\"363\" y=\"858\">%s</text>\n", missions[cur_mis].part);
	fprintf(html, "<text x=\"363\" y=\"1015\">REPORT:</text>\n");
	fprintf(html, "<text x=\"363\" y=\"1173\">Mission status:</text>\n");
	fprintf(html, "<text x=\"1004\" y=\"1173\"%s</text>\n", cur_obj == cur_mis_objs_max ? ">Completed" : " class=\"failed\">FAILED");

	for(tmp_obj = OBJ_A; tmp_obj < cur_mis_objs_max; tmp_obj++, cur_line++)
	{
		fprintf(html, "<text x=\"363\" y=\"%d\">%s</text>\n", line_rows[cur_line], diff_char[tmp_obj]);
		fprintf(html, "<text x=\"493\" y=\"%d\">%s</text>\n", line_rows[cur_line], missions[cur_mis].obj[tmp_obj][LINE1]);
		fprintf(html, "<text x=\"2032\" y=\"%d\"%s</text>\n", line_rows[cur_line], tmp_obj < cur_obj ? ">Completed" : " class=\"failed\">FAILED");
		if(missions[cur_mis].obj[tmp_obj][LINE2] != NULL) /* if objective took up two lines, skip an extra line for next objective */
		{
			fprintf(html, "<text x=\"562\" y=\"%d\">%s</text>\n", line_rows[cur_line+1], missions[cur_mis].obj[tmp_obj][LINE2]);
			cur_line++;
		}
	}

	fprintf(html, "<a onclick=\"swap_pages()\"><rect x=\"2573\" y=\"945\" height=\"434\" width=\"79\" class=\"button\"></rect></a>\n");
	fprintf(html, "</svg>\n");
	fprintf(html, "<svg viewBox=\"0 0 2880 2160\" class=\"stats\" id=\"page2\" style=\"display: none;\">\n");
	fprintf(html, "<text x=\"363\" y=\"648\">%s</text>\n", missions[cur_mis].diff);
	fprintf(html, "<text x=\"363\" y=\"754\">%s</text>\n", missions[cur_mis].title);
	fprintf(html, "<text x=\"363\" y=\"858\">%s</text>\n", missions[cur_mis].part);
	fprintf(html, "<text x=\"363\" y=\"1015\">STATISTICS:</text>\n");
	fprintf(html, "<text x=\"363\" y=\"1172\">Time:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1172\">00:02</text>\n");
	fprintf(html, "<text x=\"363\" y=\"1284\">Target:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1284\">04:00</text>\n");
	fprintf(html, "<text x=\"1250\" y=\"1284\">(Best Time: 00:10)</text>\n");
	fprintf(html, "<text x=\"363\" y=\"1416\">Decomp:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1416\">%0.1f%%</text>\n", PERCENTF(decompiled_words, decompiled_words_max));
	if(last_modified_file_arg_active)
	{
		fprintf(html, "<text x=\"363\" y=\"1520\">Last modified file:</text>\n");
		fprintf(html, "<text x=\"1180\" y=\"1520\">%s</text>\n", argv[14]);
	}
	else
	{
		fprintf(html, "<text x=\"363\" y=\"1520\">Weapon of choice:</text>\n");
		fprintf(html, "<text x=\"1246\" y=\"1520\">PP7 (silenced)</text>\n");
	}
	fprintf(html, "<text x=\"363\" y=\"1678\">Files done:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1678\">%ld</text>\n", decompiled_files);
	fprintf(html, "<text x=\"363\" y=\"1776\">Files total:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1776\">%ld</text>\n", decompiled_files_max);
	fprintf(html, "<text x=\"1180\" y=\"1678\">src:</text>\n");
	fprintf(html, "<text x=\"1800\" y=\"1678\">%ld (%0.1f%%)</text>\n", src_dir, PERCENTF(src_dir, src_dir_max));
	fprintf(html, "<text x=\"1180\" y=\"1776\">src/game:</text>\n");
	fprintf(html, "<text x=\"1800\" y=\"1776\">%ld (%0.1f%%)</text>\n", game_dir, PERCENTF(game_dir, game_dir_max));
	fprintf(html, "<text x=\"1180\" y=\"1875\">src/inflate:</text>\n");
	fprintf(html, "<text x=\"1800\" y=\"1875\">%ld (%0.1f%%)</text>\n", inflate_dir, PERCENTF(inflate_dir, inflate_dir_max));
	fprintf(html, "<text x=\"1180\" y=\"1973\">src/libultra:</text>\n");
	fprintf(html, "<text x=\"1800\" y=\"1973\">%ld (%0.1f%%)</text>\n", libultra_dir, PERCENTF(libultra_dir, libultra_dir_max));
	fprintf(html, "<a onclick=\"swap_pages()\"><rect x=\"2573\" y=\"1548\" height=\"434\" width=\"79\" class=\"button\"></rect></a>\n");
	fprintf(html, "</svg>\n");
	fprintf(html, "</div>\n");
	fprintf(html, "</body>\n");
	fprintf(html, "</html>");
	fclose(html);

	if(verbosity_level != LOG_MIN)
	{
		printf("\n  Successfully written stats to %s\n\n", argv[13]);
	}
	printf("    %s\n", missions[cur_mis].out_name);
	for(tmp_obj = OBJ_A; tmp_obj < cur_mis_objs_max; tmp_obj++)
	{
		printf("\n      [%s] %s", tmp_obj < cur_obj ? "X" : " ", missions[cur_mis].obj[tmp_obj][LINE1]);
		if(missions[cur_mis].obj[tmp_obj][LINE2] != NULL)
		{
			printf(" %s", missions[cur_mis].obj[tmp_obj][LINE2]);
		}
		if(tmp_obj == cur_obj)
		{
			printf(" - %0.1f%%", obj_remaining * 100.f);
		}
	}

	printf("\n\n    Mission Status: %s", cur_obj == cur_mis_objs_max ? "Completed" : "FAILED");
	if(total_complete == max_objs)
	{
		printf("\n\n    Baron has been defeated - decomp is complete!!");
	}

exit:
	if(verbosity_level != LOG_MIN)
	{
		printf("\n%s\n\n", LINE);
	}
	return 0;
}
