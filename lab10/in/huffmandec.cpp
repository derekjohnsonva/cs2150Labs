// inlab-skeleton.cpp
// Derek Johnson, dej3tc
// 11/26/2019

// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "heap.h"
#include "binHeapNode.h"
#include <string>
using namespace std;

void insertByBinCode(binHeapNode* root, binHeapNode* n, string s){
  if(s ==""){
    root->letter = n->letter;
    return;
  }
  
  string sSub = s.substr(0,1);
  s.erase(0,1);
  if(sSub == "0"){
    if(root->left == NULL){
      binHeapNode* x = new binHeapNode();
      root -> left = x;
      }
     insertByBinCode(root->left, n, s);
  }
  if(sSub == "1"){
    if(root->right == NULL){
      binHeapNode* xx = new binHeapNode();
      root->right = xx;
    }
    insertByBinCode(root->right, n, s);
  } 
}

void printTree(binHeapNode* root){
  if(root!=NULL){
    cout << root->letter << " " << root->binCode << endl;
    printTree(root->left);
    printTree(root->right);
  }
}

char findFromBinCode(const binHeapNode* root, string s){
  if(s==""){
    return root->letter;
  } 
  string sSub = s.substr(0,1);
  s.erase(0,1);
  if(sSub=="0"){
    return findFromBinCode(root->left, s);
  }
  return findFromBinCode(root->right, s);
}

void decodeBits(binHeapNode* root, binHeapNode* c, string s){
  if(s == ""){
    cout << c->letter;
    return;
  }
 if(c->letter != '\0'){
    cout << c->letter;
    c = root;
    decodeBits(root, c, s);   
    return; 
  }
  string sSub = s.substr(0,1);
  s.erase(0,1);
  if(sSub=="0") decodeBits(root, c->left , s);
  if(sSub=="1") decodeBits(root, c->right, s);
}
// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }


    // read in the first section of the file: the prefix codes
    // We will first create an empty tree and add to it for every
    // char we find
    binHeapNode* root = new binHeapNode();
     
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        binHeapNode* n = new binHeapNode();
        n->letter = character[0];
        insertByBinCode(root, n, prefix);
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
  //  cout << findFromBinCode(root,"0") << endl;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        if (bits[0] == '0'){
          
        }
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    cout << "All the bits when encoded: " << allbits << endl << endl;
    cout <<"----------------------------------------" << endl;
    //Decode the bits
    binHeapNode* n = root;
    cout << "The decoded text:   ";
    decodeBits(root, n, allbits);
    cout << endl;
// close the file before exiting
    file.close();
}
