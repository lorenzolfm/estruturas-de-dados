ifndef VERBOSE
.SILENT:
endif

# Compiler
CC = g++

# Compiler flags
C_FLAGS = -g -Werror

LD_FLAGS = -L $(GTEST_LIB) -l $(GTEST) -l pthread

TESTS_DIR = tests

SRCS_DIR = src

INCLUDE_DIRS = include

BUILD_DIR = build

# Gtest stuff
GTEST_LIB = /usr/lib/
GTEST = gtest

BUILD_OUTPUT = -o $(BUILD_DIR)
ARR_LIST_DEPS = $(BUILD_DIR)/array_list.o $(BUILD_DIR)/test_array_list.o


COMPILE_SRC_DEPS = $(CC) -c $(SRCS_DIR)/$(*F).cpp -I $(INCLUDE_DIRS) -o $@
COMPILE_TST_DEPS = $(CC) -c $(TESTS_DIR)/$(*F).cpp -I $(INCLUDE_DIRS) -o $@

# Test ArrayList
tal: $(ARR_LIST_DEPS)
	$(CC) $(C_FLAGS) $? $(LD_FLAGS) $(BUILD_OUTPUT)/TestArrayList
	./$(BUILD_DIR)/TestArrayList

build/array_list.o: $(SRCS_DIR)/array_list.cpp $(INCLUDE_DIRS)/array_list.h
	mkdir -p $(BUILD_DIR)
	$(COMPILE_SRC_DEPS)

build/test_array_list.o: $(TESTS_DIR)/test_array_list.cpp $(INCLUDE_DIRS)/array_list.h
	mkdir -p $(BUILD_DIR)
	$(COMPILE_TST_DEPS)

STR_LIST_DEPS = $(BUILD_DIR)/array_list.o $(BUILD_DIR)/string_list.o $(BUILD_DIR)/test_string_list.o

tsl: $(STR_LIST_DEPS)
	$(CC) $(C_FLAGS) $? $(LD_FLAGS) $(BUILD_OUTPUT)/TestStringList
	./$(BUILD_DIR)/TestStringList

build/string_list.o: $(SRCS_DIR)/string_list.cpp $(INCLUDE_DIRS)/string_list.h
	mkdir -p $(BUILD_DIR)
	$(COMPILE_SRC_DEPS)

build/test_string_list.o: $(TESTS_DIR)/test_string_list.cpp $(INCLUDE_DIRS)/string_list.h
	mkdir -p $(BUILD_DIR)
	$(COMPILE_TST_DEPS)


clean:
	rm -rf $(BUILD_DIR)
