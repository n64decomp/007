#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fread_csv_line.h"

#define READ_BLOCK_SIZE 65536
#define QUICK_GETC( ch, fp )\
do\
{\
    if ( read_ptr == read_end ) {\
        fread_len = fread( read_buf, sizeof(char), READ_BLOCK_SIZE, fp );\
        if ( fread_len < READ_BLOCK_SIZE ) {\
            read_buf[fread_len] = '\0';\
        }\
        read_ptr = read_buf;\
    }\
    ch = *read_ptr++;\
}\
while(0)
	
/*
 * Given a file pointer, read a CSV line from that file.
 * File may include newlines escaped with "double quotes".
 *
 * Warning: This function is optimized for the use case where
 *   you repeatedly call it until the file is exhausted.  It is
 *   very suboptimal for the use case of just grabbing one single
 *   line of CSV and stopping.  Also, this function advances the
 *   file position (in the fseek/ftell sense) unpredictably.  You
 *   should not change the file position between calls to
 *   fread_csv_line (e.g., don't use "getc" on the file in between
 *   calls to fread_csv_line).
 *
 * Other arguments:
 * int *done: Pointer to an int that will be set to 1 when file is exhausted.
 *
 * Warning: Calling this function on an exhausted file (as indicated by the
 *   'done' flag) is undefined behavior.
 */

char *buf = NULL;
int max_line_size = 0;

int fread_csv_alloc(int size) {
	max_line_size = size;
	buf = malloc( max_line_size );
	return buf != NULL ? 1 : 0;
}

void fread_csv_free(void) {
	free( buf );
}

char *fread_csv_line(FILE *fp, int *done) {
    static FILE *bookmark;
    static char read_buf[READ_BLOCK_SIZE], *read_ptr, *read_end;
    static int fread_len;
    char *bptr, *limit;
    char ch;
    int fQuote;

    bptr = buf;
    limit = buf + max_line_size;

    if ( bookmark != fp ) {
        read_ptr = read_end = read_buf + READ_BLOCK_SIZE;
        bookmark = fp;
    }

    for ( fQuote = 0; ; ) {
        QUICK_GETC(ch, fp);

        if ( !ch || (ch == '\n' && !fQuote)) {
            break;
        }

        if ( bptr >= limit ) {
            return NULL;
        }
        *bptr++ = ch;

        if ( fQuote ) {
            if ( ch == '\"' ) {
                QUICK_GETC(ch, fp);

                if ( ch != '\"' ) {
                    if ( !ch || ch == '\n' ) {
                        break;
                    }
                    fQuote = 0;
                }
                *bptr++ = ch;
            }
        } else if ( ch == '\"' ) {
            fQuote = 1;
        }
    }

    *done = !ch;
    *bptr = '\0';
    return buf;
}
