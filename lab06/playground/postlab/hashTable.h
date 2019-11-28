// Derek Johnson dej3tc
// 10/21/19
// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <string>
#include <deque>
using namespace std; 
class HashTable{
 public:
  HashTable(int size);
  void insert(string s);
  bool checkTable(string s);
  vector<deque<string> > table;
 private:
  int tableSize;
  int hashFunction(string s);
};
#endif
