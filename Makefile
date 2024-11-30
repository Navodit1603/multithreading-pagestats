# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# Main executable target
all: main

# Compile the main executable
main: main.o Fileread.o LinkList.o
	$(CXX) $^ -o $@

# Compile ListTest separately
listtest: ListTest.o LinkList.o
	$(CXX) $^ -o $@

# Object file rules
ListTest.o: ListTest.cpp LinkList.h
	$(CXX) $(CXXFLAGS) -c $<

Fileread.o: Fileread.cpp Fileread.h LinkList.h
	$(CXX) $(CXXFLAGS) -c $<

LinkList.o: LinkList.cpp LinkList.h
	$(CXX) $(CXXFLAGS) -c $<

main.o: main.cpp LinkList.h Fileread.h
	$(CXX) $(CXXFLAGS) -c $<

# Clean up
clean:
	rm -f *.o main listtest