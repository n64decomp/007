CFILES   = $(wildcard *.c)
OBJFILES = $(CFILES:.c=.o)
OUT      = gzip

CC      = gcc
CFLAGS  = -DSTDC_HEADERS=1 -DHAVE_UNISTD_H=1 -DDIRENT=1 -O2 

$(OUT): $(OBJFILES)

.PHONY: clean
clean:
	rm -f $(OBJFILES) $(OUT)
