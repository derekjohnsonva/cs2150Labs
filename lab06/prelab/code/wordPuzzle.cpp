
// Derek Johnson dej3tc
// 10/21/19
// wordPuzzle.cpp

// The big O run time is n^2


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include "hashTable.h"
#include "timer.h"
using namespace std;
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid (string filename, int &rows, int &cols);

char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

bool checkprime(unsigned int p);

int nextPrime(int n);

int largestWord(string filename);

int main (int argc, char* argv[]) {
  
  // Opening the dictionary file, the first file passed in
  ifstream dictionaryfile;
  string dictionary(argv[1]);
  dictionaryfile.open(dictionary);
  // Finding the number of lines in the dictionary file
  int numOfLines = 0;
  string line;
  while (getline(dictionaryfile, line)){
    numOfLines++;
  }
  //finding the largest word in the dictionary file
  // int biggestWord = largestWord(argv[1]);
  numOfLines = numOfLines*2;
  int sizeOfTable = nextPrime(numOfLines);
  // Making the Hash Table from the prime generated
  HashTable hashDict(sizeOfTable);
  string line2;
  ifstream dictionaryfile2;
  string s;
  dictionaryfile2.open(dictionary);
  while(getline(dictionaryfile2, line2)){
    s = line2;
    hashDict.insert(s);    
  }
  // Writing the grid file into a char array
  // These two variables will store the grid size
  int rows, cols;
  string gridfile = argv[2];
  gridfile.c_str();
  readInGrid(gridfile, rows, cols);
  
  // directionList is an array of the directions
  string directionList[] = {"N","NE","E","SE","S","SW","W","NW"};
  //foundWords is the number of words found in the dictionary
  int foundWords = 0;
  timer l;
  l.start();
  // We will now be checking each of the words in the 
  // grid against the words in the hash table
  // We will be using 4 for loops
  for(int r =0; r<=rows; r++){
    for(int c=0; c<=cols; c++) {
      for(int dir = 0; dir<=7; dir++) {
        for(int len = 3; len<=22 ;len++){
          string word = getWordInGrid(r,c,dir,len,rows,cols);
          if(hashDict.checkTable(word)){
            cout << directionList[dir] <<"("<<r<<", "<<c<<"):         "<<word<<endl;
            foundWords++;
            if(getWordInGrid(r,c,dir,len+1,rows,cols) == word)
              break; 
          }
        }
      }
    }
  } 
  l.stop();
  cout << foundWords <<" words found" << endl;
  cout << "Found all words in " << l.toString() << endl;
  return 0;
}

/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columnss as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
        }
    }
    // return success!
    return true;
}



/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static char[][] variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A char* containing the letters in the provided direction
 *         (NOTE: it is returned in a static char array).
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}

// Helper method for nextPrime that will check if a number is prime
bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}
//This will be a method that will take in an integer
// and return the next highest prime number
int nextPrime(int n){
  while (!checkprime(++n));
  return n;
}
int largestWord(string filename) {
  // set up the file stream to read in the file (takes in a C-style
  // char* string, not a C++ string object)
  ifstream file(filename);
  // upon an error, return false
  if ( !file.is_open() )
    return false;
  string line;
  int longestWord = 0;
  while(getline(file,line)){
    if(line.length() > longestWord)
      longestWord = line.length();
  }
  return -1;
}

