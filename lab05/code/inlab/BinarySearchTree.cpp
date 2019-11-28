#include "BinarySearchTree.h"
#include <string>
#include <iostream>
#include "BinaryNode.h"
using namespace std;

BinarySearchTree::BinarySearchTree() {
	root = NULL;
	count = 0;
}

BinarySearchTree::~BinarySearchTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
	root = insert(root, x);
	count ++;
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) { root = remove(root, x); }

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const{
        // YOUR IMPLEMENTATION GOES HERE
	if(!find(x))
		return " ";
	vector<string> v;
	findPath(root,v,x);
	string output = "";
	for(int i=0; i<v.size()-1; i++)
		output = output + v[i]+" ";
	output = output + x;
	return output;	
	
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  if(find(root, x) == NULL)
	return false;
  return true;
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
	return count;
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    count--;
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      BinaryNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      BinaryNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  return n;
}

// helper for insert
BinaryNode* BinarySearchTree::insert(BinaryNode*& n, const string& x) {
	if (n == NULL) {
		BinaryNode * t = new BinaryNode();
		t->value = x;
		return t;
	}
	// if x belongs in the left subtree
	else if (x.compare(n->value) < 0) {
		n->left = insert(n->left, x);
	}
	// if x belongs in the right subtree
	else if (x.compare(n->value) > 0) {
		n->right = insert(n->right, x);
	}
	return n;
}

//Helper for find
BinaryNode* BinarySearchTree::find(BinaryNode* n, const string& x) const{
	if (n == NULL) 
		return NULL;
	string value = n->value;
	if (x.compare(value) <0 )
		return find(n->left, x);
	else if (x.compare(value) > 0 )
		return find(n->right, x);
	else 
		return n; //found the node
}

//Helper function for pathTo
void BinarySearchTree::findPath(BinaryNode* n, vector<string>& v, const string& x) const{
	if(n!=NULL){
	string value = n->value;
	if( x == value){
		v.push_back(value);
	}
	
	if (x.compare(value) <0){
		v.push_back(value);
		findPath(n->left,v,x);
	}
	else if (x.compare(value) > 0){
		v.push_back(value);
		findPath(n->right,v,x);
	}
	}
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isLeft) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->left, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isLeft) {
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->right, trunk, false);
}

void BinarySearchTree::printTree() { printTree(root, NULL, false); }
