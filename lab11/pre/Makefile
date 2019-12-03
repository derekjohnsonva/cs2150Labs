# Derek Johnson dej3tc
# Lab at 13:30 on Tuesday
# 10/15/19

CXXFLAGS = -Wall -g -std=c++11
CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g
OFILES = topological.cpp 
.SUFFIXES: .o .cpp
all: doxy bst
doxy: Doxyfile middleearth.h middleearth.cpp topological.cpp
	doxygen Doxyfile

bst: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 
topological.o: topological.cpp	
	$(CXX) -c topological.cpp

clean:
	 -rm -f *.o *~bst
