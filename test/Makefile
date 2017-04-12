GTEST_DIR = ../googletest/googletest

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

CXXFLAGS += -g -Wall -Wextra -pthread

CPPFLAGS += -isystem $(GTEST_DIR)/include

LIB = $(GTEST_DIR)/make/gtest_main.a

TESTS = test_ut

## all: $(TESTS)

build/test.o: ./test.cxx $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) -c ./test.cxx -o build/test.o

test: build/test.o $(LIB)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o bin/$@
