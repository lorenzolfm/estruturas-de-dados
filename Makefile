# Name of the component, used for the executable
PROJECT_NAME = DataStructures

# Compiler
CC = g++

# Compiler flags
C_FLAGS = -g -Werror

# Gtest stuff
GTEST_LIB = /usr/lib/
GTEST = gtest

# Linker flags
LD_FLAGS = -L $(GTEST_LIB) -l $(GTEST) -l pthread

# Binary output option
BUILD_OUTPUT = -o build/$(COMPONENT_NAME)

# Array Stack
ARRAY_STACK_TESTS_DIR = Array-Stack/tests
ARRAY_STACK_SRC_DIR = Array-Stack/src
ARRAY_STACK_INCLUDE_DIR = Array-Stack/include

# Build and execute tests
test:
	mkdir -p build
	$(CC) $(C_FLAGS) $(ARRAY_STACK_TESTS_DIR)/*.cpp $(ARRAY_STACK_SRC_DIR)/*.cpp -I $(ARRAY_STACK_INCLUDE_DIR) $(LD_FLAGS) $(BUILD_OUTPUT)
	./build/$(COMPONENT_NAME)

DOCS_OUT_DIR = docs

export DOCS_OUT_DIR = docs
export DOXYGEN_PROJECT_NAME = $(PROJECT_NAME)
export DOXYGEN_GENERATE_LATEX = NO
export DOXYGEN_GENERATE_TREEVIEW = YES
export DOXYGEN_ALPHABETICAL_INDEX = NO
export DOXYGEN_OUTPUT_DIRECTORY = $(DOCS_OUT_DIR)
export DOXYGEN_RECURSIVE = YES
export DOXYGEN_HTML_OUTPUT = .

doc:
	@doxygen
	@echo "Documentation @ ${DOCS_OUT_DIR}/index.html"

format:
	find \
	Array-Stack \
	-name "*.h" \
	-o -name "*.cpp" \
	| xargs clang-format -i .clang-format

# Clean build and docs directories
clean:
	rm -rf build
	rm -rf docs
