ifndef VERBOSE
.SILENT:
endif

# Name of the component, used for the executable
COMPONENT_NAME = TestArrayStack

# Compiler
CC = g++

# Compiler flags
C_FLAGS = -g -Werror

TESTS_DIR = tests

SRCS_DIR = src

INCLUDE_DIRS = include

BUILD_DIR = build

# Gtest stuff
GTEST_LIB = /usr/lib/
GTEST = gtest

# Linker flags
LD_FLAGS = -L $(GTEST_LIB) -l $(GTEST) -l pthread

OBJECTS = $(BUILD_DIR)/array_stack.o $(BUILD_DIR)/test_array_stack.o

OBJECT_SOURCES = $(SRCS_DIR)/array_stack.cpp $(INCLUDE_DIRS)/array_stack.h
TEST_OBJECT_SOURCES = $(TESTS_DIR)/test_array_stack.cpp $(INCLUDE_DIRS)/array_stack.h

# Binary output option
BUILD_OUTPUT = -o $(BUILD_DIR)/$(COMPONENT_NAME)

# Build and execute tests
test: $(OBJECTS)
	$(CC) $(C_FLAGS) $? $(LD_FLAGS) $(BUILD_OUTPUT)
	./$(BUILD_DIR)/$(COMPONENT_NAME)

build/array_stack.o: $(OBJECT_SOURCES)
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(SRCS_DIR)/$(*F).cpp -I $(INCLUDE_DIRS) -o $@

build/test_array_stack.o: $(TEST_OBJECT_SOURCES)
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(TESTS_DIR)/$(*F).cpp -I $(INCLUDE_DIRS) -o $@

# Clean build and docs directories
clean:
	rm -rf $(BUILD_DIR)
