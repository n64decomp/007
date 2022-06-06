CC := gcc
CXX := g++
MAKE := make
CFLAGS := -I . -Wall -Wextra -Wno-unused-parameter -pedantic -std=c99 -O2 -s
LDFLAGS := -lm
PROGRAMS := n64cksum

# if armips is not found on the system, build it in tools
ifeq (, $(shell which armips 2> /dev/null))
CXX_PROGRAMS += armips
endif

default: all

armips: armips.cpp
	$(CXX) $(CXXFLAGS) -fno-exceptions -fno-rtti -pipe $^ -o $@ -lpthread $(ARMIPS_FLAGS)

n64cksum_SOURCES := n64cksum.c utils.c
n64cksum_CFLAGS := -DN64CKSUM_STANDALONE

GZIP := gzipsrc/gzip

$(GZIP):
	@$(MAKE) -C gzipsrc

ifneq ($(IDO_RECOMP), NO)

IDO53 := ido5.3_recomp/cc

$(IDO53):
	@$(MAKE) -C ido5.3_recomp
endif

all: $(GZIP) $(PROGRAMS) $(CXX_PROGRAMS) $(IDO53)

clean:
	$(RM) $(PROGRAMS) $(CXX_PROGRAMS)
	$(MAKE) -C gzipsrc clean

define COMPILE
$(1): $($1_SOURCES)
	$(CC) $(CFLAGS) $($1_CFLAGS) $$^ -o $$@ $(LDFLAGS) $($1_LDFLAGS)
endef

$(foreach p,$(PROGRAMS),$(eval $(call COMPILE,$(p))))

.PHONY: all clean default
