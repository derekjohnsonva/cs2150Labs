// Derek Johnson dej3tc
// 10/17/19
//AVLTree.h

#ifndef AVL_H
#define AVL_H

#include <string>
#include <vector>
#include "AVLNode.h"

using namespace std;

struct Trunk {
  Trunk* prev;
  string str;

  Trunk(Trunk* prev, string str) {
    this->prev = prev;
    this->str = str;
  }
};

class AVLTree {
 public:
  AVLTree();
  ~AVLTree();

  // insert finds a position for x in the tree and places it there, rebalancing
  // as necessary.
  void insert(const string& x);
  // remove finds x's position in the tree and removes it, rebalancing as
  // necessary.
  void remove(const string& x);
  // printTree pretty-prints the tree to aid debugging.
  void printTree();

  // pathTo finds x in the tree and returns a string representing the path it
  // took to get there.
  string pathTo(const string& x) const;
  // find determines whether or not x exists in the tree.
  bool find(const string& x) const;
  // numNodes returns the total number of nodes in the tree.
  int numNodes() const;

 private:
  // Declare a root node
  AVLNode* root;

  // balance makes sure that the subtree with root n maintains the AVL tree
  // property, namely that the balance factor of n is either -1, 0, or 1.
  void balance(AVLNode*& n);
  // rotateLeft performs a single rotation on node n with its right child.
  AVLNode* rotateLeft(AVLNode*& n);
  // rotateRight performs a single rotation on node n with its left child.
  AVLNode* rotateRight(AVLNode*& n);

  // private helper for remove to allow recursion over different nodes. returns
  // an AVLNode* that is assigned to the original node.
  AVLNode* remove(AVLNode*& n, const string& x);
  // min finds the string with the smallest value in a subtree.
  string min(AVLNode* node) const;
  // height returns the value of the height field in a node. If the node is
  // null, it returns -1.
  int height(AVLNode* node) const;

  // private helper for printTree to allow recursion over different nodes.
  void printTree(AVLNode* root, Trunk* prev, bool isLeft);

  // Any other methods you need...
  int balanceFactor(AVLNode*& n);

  //Helper Method for insert that will allow it to recursivly look through 
  // the AVLTree
  AVLNode* insert(AVLNode*& n, const string& x);
  // a counter int that will alow us to easily find the size of the tree
  AVLNode* find(AVLNode* n, const string& x) const;
  void findPath(AVLNode* n, vector<string>& v, const string& x) const;
 
  int count;
};

// max returns the greater of two integers.
int max(int a, int b);

#endif
