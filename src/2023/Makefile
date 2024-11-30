CXX = clang++

BIN_DIR = $(PWD)/bin
INCLUDE_DIR = $(PWD)/include
SRC_DIR = $(PWD)/src
TESTS_DIR = $(PWD)/tests
VENDOR_DIR = $(PWD)/vendor

CXXFLAGS += -std=c++20 -Wall -Wextra -Wpedantic -I$(INCLUDE_DIR) -I$(VENDOR_DIR)
LDFLAGS += -lm

SOURCES = $(wildcard $(SRC_DIR)/??.cpp $(SRC_DIR)/problem.cpp $(SRC_DIR)/utils.cpp)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))

TEST_SOURCES = $(patsubst $(SRC_DIR)/%,$(TESTS_DIR)/test-%,$(SOURCES))

.SUFFIXES:
.SUFFIXES: .cpp .o

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $< -o $@

main: $(BIN_DIR)/main
	$(BIN_DIR)/main

tests: $(BIN_DIR)/tests
	$(BIN_DIR)/tests

$(BIN_DIR)/main: $(OBJECTS) $(SOURCES) $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SRC_DIR)/main.cpp $(OBJECTS) -o $@

$(BIN_DIR)/tests: $(OBJECTS) $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) \
	    $(VENDOR_DIR)/catch_amalgamated.cpp $(TEST_SOURCES) $(OBJECTS) -o $@

.PHONY: clean
clean:
	rm -rf $(OBJECTS)

.PHONY: distclean
distclean: clean
	rm -rf $(BIN_DIR)/*
