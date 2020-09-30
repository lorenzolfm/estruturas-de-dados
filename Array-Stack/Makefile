# Name of the component, used for the executable
COMPONENT_NAME = ArrayStack

# Compiler
CC = g++

# Compiler flags
C_FLAGS = -g -Werror

TESTS_DIR = tests

SRCS_DIR = src

INCLUDE_DIRS = include

# Gtest stuff
GTEST_LIB = /usr/lib/
GTEST = gtest

# Linker flags
LD_FLAGS = -L $(GTEST_LIB) -l $(GTEST) -l pthread

# Binary output option
BUILD_OUTPUT = -o build/$(COMPONENT_NAME)

# Build and execute tests
test:
	mkdir -p build
	$(CC) $(C_FLAGS) $(TESTS_DIR)/*.cpp $(SRCS_DIR)/*.cpp -I $(INCLUDE_DIRS) $(LD_FLAGS) $(BUILD_OUTPUT)
	./build/$(COMPONENT_NAME)

# Clean build and docs directories
clean:
	rm -rf build
