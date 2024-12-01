CC = clang

BIN_DIR = $(PWD)/bin
INCLUDE_DIR = $(PWD)/include
SRC_DIR = $(PWD)/src
TESTS_DIR = $(PWD)/tests

CFLAGS += -Wall -Wextra -Wpedantic -std=c17 -I/opt/homebrew/include -I$(INCLUDE_DIR)
LDFLAGS += -L/opt/homebrew/lib -lm -lcmocka

SOURCES = $(wildcard $(SRC_DIR)/??.c $(SRC_DIR)/utils.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

TEST_SOURCES = $(wildcard $(TESTS_DIR)/test-??.c)
TEST_OBJECTS = $(patsubst %.c,%.o,$(TEST_SOURCES))

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

run: tests main

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) $(SRC_DIR)/main.c -o $(BIN_DIR)/$@
	$(BIN_DIR)/$@ $(PWD)/../../data/2024/

tests: $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(TESTS_DIR) $(TEST_OBJECTS) $(OBJECTS) $(TESTS_DIR)/tests.c -o $(BIN_DIR)/$@
	$(BIN_DIR)/$@

clean:
	rm -rf $(OBJECTS) $(TEST_OBJECTS)
	rm -rf $(BIN_DIR)/*

.PHONY: clean main tests
