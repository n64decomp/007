#Compiler
CC = @gcc

#Source directories
SRCDIR = ./
OUTNAME = aaa_rip

#Compiler flags
CFLAGS = -shared -ansi -Os -std=c89
CFLAGSDBG = -shared -ansi -g -std=c89
WFLAGS = -W -Wall -Wextra -pedantic -Wunreachable-code -Wno-unused-result

#Linker flags
OBJS = $(SRCDIR)main.o
LFLAGS = $(OBJS) -o $(OUTNAME) -s
LFLAGSDBG = $(OBJS) -o $(OUTNAME)

#Main recipes
all: aaa_rip

debug: CC = gcc
debug: CFLAGS = $(CFLAGSDBG)
debug: LFLAGS = $(LFLAGSDBG)
debug: aaa_rip

aaa_rip: $(OBJS)
	$(CC) $(LFLAGS)

clean:
	@rm $(OUTNAME)
	@rm $(SRCDIR)*.o

#Individual recipes
$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) -c $(SRCDIR)main.c -o $(SRCDIR)main.o $(CFLAGS) $(WFLAGS)