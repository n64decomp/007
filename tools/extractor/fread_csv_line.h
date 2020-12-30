#ifndef CSV_DOT_H_INCLUDE_GUARD
#define CSV_DOT_H_INCLUDE_GUARD

int fread_csv_alloc(int size);
void fread_csv_free(void);
char *fread_csv_line(FILE *fp, int *done);

#endif
