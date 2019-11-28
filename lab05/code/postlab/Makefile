# Derek Johnson dej3tc
# Lab at 13:30 on Tuesday
# 10/17/19

CXXFLAGS = -Wall -O2 -std=c++11
CXX=clang++ $(CXXFLAGS)
DEBUG = -Wall -g
OFILES = AVLNode.o AVLPathTest.o AVLTree.o

.SUFFIXES: .o .cpp
avl: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)
	@echo "avl tree is prepaired"
AVLNode.o: AVLNode.cpp AVLNode.h
	$(CXX) -c AVLNode.cpp
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
	$(CXX) -c AVLPathTest.cpp
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.h
	$(CXX) -c AVLTree.cpp

clean:
	-rm -f *.o *~avl
