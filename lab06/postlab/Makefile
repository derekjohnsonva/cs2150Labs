# Derek Johnson dej3tc
# Lab at 13:30 on Tuesday
# 10/17/19

CXXFLAGS = -Wall -g -O2 -std=c++11 
CXX=clang++ $(CXXFLAGS)
DEBUG = -Wall -g
OFILES = hashTable.o timer.o wordPuzzle.o

.SUFFIXES: .o .cpp
puzzle: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)
	@echo "puzzle is prepaired"
hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp
timer.o: timer.cpp timer.h
	$(CXX) -lrt -c timer.cpp
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
	$(CXX) -c wordPuzzle.cpp

clean:
	-rm -f *.o *~puzzle
