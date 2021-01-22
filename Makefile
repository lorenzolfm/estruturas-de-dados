# Silent make
ifndef VERBOSE
.SILENT:
endif

# Compiler
CC = g++

# Compiler Flags
CPP_FLAGS = -Werror

# Linker flags
LD_FLAGS = -L /usr/lib/ -l gtest -l pthread

# Build directory
BUILD_DIR := build
# Include directory (.h files)
INCLUDE_DIR := include
# Source directory (.cpp files)
SRC_DIR := src
# Test directory
TEST_DIR := test

# Source objects directory (.o files)
SRCS_OBJS_DIR := $(BUILD_DIR)/objs

# Tests objects directory (.o files)
TESTS_OBJS_DIR := $(SRCS_OBJS_DIR)/tests

# List of all files matching this pattern (with directory)
SRCS = $(wildcard src/*.cpp)
TESTS = $(wildcard tests/*cpp)
# List of all files matching this pattern (file only)
SRCS_FILES = $(notdir $(SRCS))
TESTS_FILES = $(notdir $(TESTS))

# Substitutes the file extension from %.cpp to %.o and sets the corrrect path
OBJS := $(patsubst %.cpp, $(SRCS_OBJS_DIR)/%.o, $(SRCS_FILES))
TEST_OBJS := $(patsubst %.cpp, $(TESTS_OBJS_DIR)/%.o, $(TESTS_FILES))

# Dependencies directory
DEPDIR = $(SRCS_OBJS_DIR)/.deps

# Dependencies flags
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

# Build object files
COMPILE = $(CC) -I $(INCLUDE_DIR) $(DEPFLAGS) $(CPP_FLAGS) -c

%.o : %.cpp

$(SRCS_OBJS_DIR)/%.o : $(SRC_DIR)/%.cpp $(DEPDIR)/%.d | $(DEPDIR)
	mkdir -p $(BUILD_DIR)
	$(COMPILE) $< -o $@

$(TESTS_OBJS_DIR)/%.o : $(TEST_DIR)/%.cpp $(DEPDIR)/%.d | $(DEPDIR)
	mkdir -p $(SRCS_OBJS_DIR)/tests
	$(COMPILE) $< -o $@

test: $(TEST_OBJS) $(OBJS)
	$(CC) $(TESTS) $(SRCS) -I $(INCLUDE_DIR) $(LD_FLAGS) -o $(BUILD_DIR)/test
	./build/test

clean:
	rm -rf build

# Create dependencies directory
$(DEPDIR): ; @mkdir -p $@

# Creates dependencies
DEPFILES := $(SRCS_FILES:%.cpp=$(DEPDIR)/%.d) $(TESTS_FILES:%.cpp=$(DEPDIR)/%.d)
$(DEPFILES):

include $(wildcard $(DEPFILES))
