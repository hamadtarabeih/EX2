CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = tree
TEST_TARGET = test
OBJS = Tree.o main.o
TEST_OBJS = test_tree.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp Tree.cpp Complex.cpp
	$(CXX) $(CXXFLAGS) -c Tree.cpp main.cpp Complex.cpp

test: test_tree.cpp Tree.cpp Complex.cpp doctest.h
	$(CXX) $(CXXFLAGS) -o test Tree.cpp test_tree.cpp TestCounter.cpp Complex.cpp

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJS) $(TEST_OBJS)
