# Derek Johnson dej3tc
# Lab at 13:30 on Tuesday
# 10/15/19

CXXFLAGS = -Wall -g -std=c++11
CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g
OFILESD = huffmandec.o heap.o binHeapNode.o
OFILESE = huffmanenc.o heap.o binHeapNode.o


.SUFFIXES: .o .cpp
all: decode encode

decode: $(OFILESD)
	$(CXX) -o decoder $(DEBUG) $(OFILESD) 
encode: $(OFILESE)
	$(CXX) -o encoder $(DEBUG) $(OFILESE) 
huffmandec.o: huffmandec.cpp binHeapNode.cpp binHeapNode.h heap.cpp heap.h	
	$(CXX) -c huffmandec.cpp
huffmanenc.o: huffmanenc.cpp binHeapNode.cpp binHeapNode.h heap.cpp heap.h	
	$(CXX) -c huffmanenc.cpp

heap.o: heap.cpp heap.h
	$(CXX) -c heap.cpp
binHeapNode.o: binHeapNode.cpp binHeapNode.h	
	$(CXX) -c binHeapNode.cpp

clean:
	 -rm -f *.o *~bst
