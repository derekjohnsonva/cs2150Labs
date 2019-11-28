#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
#include "BinaryNode.h"

using namespace std;

struct Trunk {
  Trunk* prev;
  string str;

  Trunk(Trunk* prev, string str) {
    this->prev = prev;
    this->str = str;
  }
};

class BinarySearchTree {
 public:
  BinarySearchTree();
  ~BinarySearchTree();

  // insert finds a position for x in the tree and places it there.
  void insert(const string& x);
  // remove finds x's position in the tree and removes it.
  void remove(const string& x);
  // printTree pretty-prints the tree to aid debugging.
  void printTree();

  // pathTo finds x in the tree and returns a string representing the path it
  // took to get there.
  string pathTo(const string& x)const ;
  // find determines whether or not x exists in the tree.
  bool find(const string& x) const;
  // numNodes returns the total number of nodes in the tree.
  int numNodes() const;

 private:
  // Declare a root node
  BinaryNode* root;
  // Keeps a count of the number of nodes in the tree
  int count;
  
  // private helper for remove to allow recursion over different nodes. returns
  // a BinaryNode* that is assigned to the original node.
  BinaryNode* remove(BinaryNode*& n, const string& x);
  // Private helper for insert to allow recursion
  BinaryNode* insert(BinaryNode*& n, const string& x);
  // Private helper for find to allow recursion
  BinaryNode* find(BinaryNode* n, const string& x) const;
  void findPath(BinaryNode* n, vector<string>& v, const string& x) const;
  
  // min finds the string with the smallest value in a subtree.
  string min(BinaryNode* node) const;
  
  // private helper for printTree to allow recursion over different nodes.
  void printTree(BinaryNode* root, Trunk* prev, bool isLeft);

  // Any other methods you need...
};

#endif
