ifndef VERBOSE
.SILENT:
endif

# Name of the component, used for the executable
COMPONENT_NAME = TestArrayQueue

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

BUILD_OUTPUT = -o $(BUILD_DIR)/$(COMPONENT_NAME)

# Linker flags
LD_FLAGS = -L $(GTEST_LIB) -l $(GTEST) -l pthread

ARR_QUEUE_DEPS = $(BUILD_DIR)/array_queue.o $(BUILD_DIR)/test_array_queue.o
ARR_QUEUE_BUILD_OUTPUT = -o $(BUILD_DIR)/$(COMPONENT_NAME)

# Test ArrayQueue
taq: $(ARR_QUEUE_DEPS)
	$(CC) $(C_FLAGS) $? $(LD_FLAGS) $(BUILD_OUTPUT)
	./$(BUILD_DIR)/$(COMPONENT_NAME)

build/array_queue.o: $(SRCS_DIR)/array_queue.cpp $(INCLUDE_DIRS)/array_queue.h
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(SRCS_DIR)/$(*F).cpp -I $(INCLUDE_DIRS) -o $@

build/test_array_queue.o: $(TESTS_DIR)/test_array_queue.cpp $(INCLUDE_DIRS)/array_queue.h
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(TESTS_DIR)/$(*F).cpp -I $(INCLUDE_DIRS) -o $@

tcq: $(BUILD_DIR)/circular_array_queue.o $(BUILD_DIR)/array_queue.o $(BUILD_DIR)/test_circular_array_queue.o
	$(CC) $(C_FLAGS) $? $(LD_FLAGS) -o $(BUILD_DIR)/TestCircularArrayQueue
	./$(BUILD_DIR)/TestCircularArrayQueue

build/circular_array_queue.o: $(SRCS_DIR)/circular_array_queue.cpp $(INCLUDE_DIRS)/circular_array_queue.h
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(SRCS_DIR)/$(*F).cpp -I $(INCLUDE_DIRS) -o $@

build/test_circular_array_queue.o: $(TESTS_DIR)/test_circular_array_queue.cpp $(INCLUDE_DIRS)/circular_array_queue.h
	mkdir -p $(BUILD_DIR)
	$(CC) -c $(TESTS_DIR)/$(*F).cpp -I $(INCLUDE_DIRS) -o $@

all:
	$(MAKE) taq
	$(MAKE) tcq

# Clean build and docs directories
clean:
	rm -rf build
