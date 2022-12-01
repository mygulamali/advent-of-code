CC = clang

BIN_DIR = $(PWD)/bin
INCLUDE_DIR = $(PWD)/src/2020/include
SRC_DIR = $(PWD)/src/2020/src
VENDOR_DIR = $(PWD)/vendor

CFLAGS += -Wall -Wextra -Wpedantic -std=c11 -I$(INCLUDE_DIR)
LDFLAGS += -lm

SOURCES = $(wildcard $(SRC_DIR)/0*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
DSYMS = $(patsubst %.c, %.dSYM, $(SOURCES))
EXES = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SOURCES))

.SUFFIXES:
.SUFFIXES: .c .o

all: $(EXES)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRC_DIR)/utils.c $< -o $@

2020:
	$(BIN_DIR)/2020/01 $(PWD)/data/2020/01.txt
	$(BIN_DIR)/2020/02 $(PWD)/data/2020/02.txt

.PHONY: clean
clean:
	rm -rf $(DSYMS) $(OBJECTS) $(EXES)

.PHONY: distclean
distclean: clean
	rm -rf $(BIN_DIR)
