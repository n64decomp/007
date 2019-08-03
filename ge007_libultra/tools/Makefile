CC := gcc
CFLAGS := -I . -Wall -Wextra -pedantic -std=c99 -O3 -s
PROGRAMS := patch_libultra_math

patch_libultra_math_SOURCES := patch_libultra_math.c

all: $(PROGRAMS)

clean:
	$(RM) $(PROGRAMS)

define COMPILE
$(1): $($1_SOURCES)
	$(CC) $(CFLAGS) $($1_CFLAGS) $$^ -lm -o $$@
endef

$(foreach p,$(PROGRAMS),$(eval $(call COMPILE,$(p))))