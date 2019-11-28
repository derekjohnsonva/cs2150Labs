# Derek Johnson dej3tc
# Lab at 13:30 on Tuesday
# 10/15/19

CXXFLAGS = -Wall -O2 -std=c++11
CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g
OFILES = BSTPathTest.o BinaryNode.o BinarySearchTree.o

.SUFFIXES: .o .cpp
bst: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 
	@echo "binary search tree is prepaired"
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
	$(CXX) -c BSTPathTest.cpp
BinaryNode.o: BinaryNode.cpp BinaryNode.h
	$(CXX) -c BinaryNode.cpp
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h	
	$(CXX) -c BinarySearchTree.cpp

clean:
	 -rm -f *.o *~bst
