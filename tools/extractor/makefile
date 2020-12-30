#Compiler
CC = @gcc

#Source directories
SRCDIR = ./
OUTNAME = extractor

#Compiler flags
CFLAGS = -shared -ansi -Os -std=c89
CFLAGSDBG = -shared -ansi -g -std=c89
WFLAGS = -W -Wall -Wextra -pedantic -Wunreachable-code -Wno-unused-result

#Linker flags
OBJS = $(SRCDIR)main.o $(SRCDIR)puff.o $(SRCDIR)fread_csv_line.o
LIBS = -lpthread
LFLAGS = $(OBJS) -o $(OUTNAME) $(LIBS) -s
LFLAGSDBG = $(OBJS) -o $(OUTNAME) $(LIBS)

#Main recipes
all: extractor

debug: CC = gcc
debug: CFLAGS = $(CFLAGSDBG)
debug: LFLAGS = $(LFLAGSDBG)
debug: extractor

extractor: $(OBJS)
	$(CC) $(LFLAGS)

clean:
	@rm $(OUTNAME)
	@rm $(SRCDIR)*.o

#Individual recipes
$(OBJDIR)main.o: $(SRCDIR)main.c $(SRCDIR)puff.h $(SRCDIR)fread_csv_line.h
	$(CC) -c $(SRCDIR)main.c -o $(SRCDIR)main.o $(CFLAGS) $(WFLAGS)

$(OBJDIR)puff.o: $(SRCDIR)puff.c $(SRCDIR)puff.h
	$(CC) -c $(SRCDIR)puff.c -o $(SRCDIR)puff.o $(CFLAGS) $(WFLAGS)

$(OBJDIR)fread_csv_line.o: $(SRCDIR)fread_csv_line.c $(SRCDIR)fread_csv_line.h
	$(CC) -c $(SRCDIR)fread_csv_line.c -o $(SRCDIR)fread_csv_line.o $(CFLAGS) $(WFLAGS)
