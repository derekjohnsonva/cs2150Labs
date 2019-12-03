# Derek Johnson dej3tc
# Lab at 13:30 on Tuesday
# 10/15/19

CXXFLAGS = -Wall -g -O2 -std=c++11
CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g
OFILES = traveling.o middleearth.o
.SUFFIXES: .o .cpp
all: doxy bst
doxy: Doxyfile middleearth.h middleearth.cpp traveling.cpp
	doxygen Doxyfile

bst: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 
traveling.o: traveling.cpp	
	$(CXX) -c traveling.cpp
middleearth.o: middleearth.cpp middleearth.h	
	$(CXX) -c middleearth.cpp


clean:
	 -rm -f *.o *~bst
