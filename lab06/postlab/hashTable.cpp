// Derek Johnson dej3tc
// 10/21/19
// HashTable.cpp

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "hashTable.h"
using namespace std;
#define hashCode 37
HashTable::HashTable(int size){
  tableSize = size;
  table.resize(size);
}
// For this hash table, the hash function will
// be the sum of the integer values of the
// character in the string, each multiplied
// by a successive power of 37
//int HashTable::hashFunction(string s) {
//  int size = s.length();
//  double long hash = 0;
//  for(int i=0; i<size; i++){
//    hash += (int)s.at(i);
//  }
//  return hash;
//}

int HashTable::hashFunction(string s){
  double size = (double)s.length();
  int sizediv = size/4;
  unsigned long hash = 0;
  for(int i=0; i<sizediv; i++){
    int pow = 1;
    for(int j=0; j < 4; j++) {
      hash += ((int)s.at((i*4)+j)) * pow;
      pow *= 227;
    }
  }
  return hash % tableSize;
}


//int HashTable::hashFunction(string s){
//  int size = s.length();
//  unsigned long hash = 0;
//  int pow = 1;
//  for(int i =0; i<size; i++){
//    hash += ((int)s.at(i)) * (hashCode^(pow));
//    pow++;
//  }
//  int position = hash % tableSize;
//  return position;
//}

void HashTable::insert(string s){
  int size = s.length();
  if(size > 2){
    int hash = hashFunction(s);
    table[hash].push_back(s);
  }
}

bool HashTable::checkTable(string s) {
  int hash = hashFunction(s);
  list<string>::iterator it = table[hash].begin();
  while(it != table[hash].end()){
    if(*it == s){
      return true;
      }
    it++;
  }
  return false;
}
