# Derek Johnson dej3tc
# Lab at 13:30 on Tuesday
# 10/15/19

CXXFLAGS = -Wall -g -std=c++11
CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g
OFILES = huffmandec.o heap.o binHeapNode.o

.SUFFIXES: .o .cpp
bst: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 
	@echo "binary search tree is prepaired"
#BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
#	$(CXX) -c BSTPathTest.cpp
#huffmanenc.o: huffmanenc.cpp binHeapNode.cpp binHeapNode.h heap.cpp heap.h	
#	$(CXX) -c huffmanenc.cpp
huffmandec.o: huffmandec.cpp binHeapNode.cpp binHeapNode.h heap.cpp heap.h	
	$(CXX) -c huffmandec.cpp

heap.o: heap.cpp heap.h
	$(CXX) -c heap.cpp
binHeapNode.o: binHeapNode.cpp binHeapNode.h	
	$(CXX) -c binHeapNode.cpp

clean:
	 -rm -f *.o *~bst
