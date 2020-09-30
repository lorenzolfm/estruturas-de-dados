#ifndef SILENCE
	#SILENCE = @
#endif

#COMPONENT_NAME = ArrayStack

CC = g++
#CFLAGS = -g -Wall

#SRC_DIRS = src

#TEST_SRC_DIRS = tests

#INCLUDE_DIRS = include

#LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) pthread

#GTEST = /usr/src/gtest/include
#LIBGTEST = /usr/lib/libgtest_main.a
#TESTDIR = tests

COMPONENT_NAME = ArrayStack

TESTS_DIR = tests

SRCS_DIR = src

INCLUDE_DIRS = include

GTEST_LIB = /usr/lib/
GTEST = gtest

LD_FLAGS = -L $(GTEST_LIB) -l $(GTEST) -l pthread

BUILD_OUTPUT = -o build/$(COMPONENT_NAME)

test:
	mkdir -p build
	$(CC) -g -Werror $(TESTS_DIR)/*.cpp $(SRCS_DIR)/*.cpp -I $(INCLUDE_DIRS) $(LD_FLAGS) $(BUILD_OUTPUT)
	./build/$(COMPONENT_NAME)

clean:
	rm -rf build
