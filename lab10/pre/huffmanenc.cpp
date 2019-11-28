// Derek Johnson, dej3tc
// 11/24/2019

// huffmanenc.cpp

#include "heap.h"
#include "binHeapNode.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;
// This is a helper method that will help us to make the binary
// code table in the main method
void makeEncTable(binHeapNode* n, string s, map<char, string>* enc){
  if (n == nullptr) return;
  if(n->letter != '\0'){
    char c = n->letter;
    enc->insert (std::pair<char, string>(n->letter, s));
  }
  makeEncTable(n->left, s+"0", enc);
  makeEncTable(n->right, s+"1", enc);
}

void printTree(binHeapNode* n){
  if (n == NULL) return;
  if(n->letter == '\0'){
    cout << "emptyNode with freq " << n->freq << endl;
  }
  else{
    cout << n->letter << " " << n->freq << endl;
  }
  printTree(n->left);
  printTree(n->right);
}

int main (int argc, char **argv) {
  if ( argc != 2) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }
  FILE *fp = fopen(argv[1], "r");
  if ( fp == NULL ) {
    cout << "file does not exist" << endl;
    exit(2);
  }

// Building the frequency table is done with the stl Map data type
// the map will be called charMap. The char is the key, and the int
// will represent the frequency
  map<char, int> charMap;
  char g;

  while ( (g=fgetc(fp)) !=EOF )
    if(g !='\n' && g!='\t' && g != '\n')
    charMap[g] += 1;

// The next step will be to make binHeapNodes from the Map and push them
// onto a BinaryHeap
  BinaryHeap * heap = new BinaryHeap();
  map<char, int>::iterator it=charMap.begin();

  for( ; it!=charMap.end(); it++){
    binHeapNode * n = new binHeapNode();
    n->letter = it->first;
    n->freq = it->second;
    heap -> insert(n); 
  }  

// This next step will build the tree
  while ( heap->size() >1){
    binHeapNode * n = new binHeapNode();
    n->freq += heap->getNode(1)->freq;
    n->left = heap->deleteMin();
    n->freq += heap->getNode(1)->freq;  
    if(heap->size() !=1){
      n->right = heap->deleteMin();
      heap->insert(n);
    }
    else{
      n->right = heap->getNode(1);
      heap->insert(n);
      heap->deleteMin();
    }  
  }
  map<char, string>* bitEnc = new map<char, string>;
  makeEncTable(heap->getNode(1),"",bitEnc);
  map<char, string>::iterator it2=bitEnc->begin();

  float encCost;
  for( ;it2 != bitEnc->end(); it2++){
    if(it2->first == ' ')
      cout << "space " << it2->second << endl;
    else{
    cout <<it2->first << " " << it2->second << endl;
    }
    encCost += (it2->second.length()) * charMap[it2->first];
  }

  cout << "----------------------------------------" << endl;
  rewind(fp);
  map<char, string> bE = *bitEnc;
// int symbolNumber = number of symbols in the file
  int symbolNumber = 0;
  int bitNumber = 0;
  while ( (g = fgetc(fp)) != EOF ){
    if(g != '\t' && g != '\n' && g != '\n') symbolNumber ++;
    bitNumber += bE[g].length();
    cout << bE[g] << " ";
  }
  fclose(fp);
  cout << endl;
  cout << "----------------------------------------" << endl;
  
  cout << "There are a total of " << symbolNumber <<
    " symbols that are encoded" << endl;
  int distinctSymbols = bE.size()-1; 
  cout << "There are " << distinctSymbols << 
    " distint symbols used" << endl;
  int bitNum = symbolNumber * 8;
  
  cout << "There were " << bitNum << " bits in the original file"
    << endl;
  
  cout << "There were " << bitNumber << " Bits in the compressed file"  << endl;
  float compRatio = (float)(bitNum) / (float)bitNumber;
  cout << "This gives a compression ratio of " << compRatio << endl;
  
  encCost /= symbolNumber;
  cout << "The Huffman tree cost is " << encCost << endl;
   
}


