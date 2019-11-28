// Derek Johnson dej3tc
// 10/17/19
// AVLTree.cpp

#include "AVLTree.h"
#include <string>
#include <iostream>
#include "AVLNode.h"
using namespace std;

AVLTree::AVLTree() {
  root = NULL;
  count = 0;
}

AVLTree::~AVLTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  root = insert(root, x);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { 
  root = remove(root, x); 
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
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
bool AVLTree::find(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  if(find(root, x) == NULL)
	return false;
  return true;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
  return count;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  if(balanceFactor(n) >=2) {
    if(balanceFactor(n->right) < 0) {
      n->right = rotateRight(n->right);
    }  
    n = rotateLeft(n);
  }
  else if(balanceFactor(n) <= -2) {
    if(balanceFactor(n->left) > 0) {
      n->left = rotateLeft(n->left);
    }
    n = rotateRight(n);
  }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  AVLNode * nright = n->right ;
  AVLNode * nrightleft = nright->left;

  nright->left = n;
  n->right = nrightleft;
  
  n->height = max(height(n->left),height(n->right))+1;
  nright->height = max(height(nright->left),height(nright->right))+1;
  return nright;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  //nleft is the left value of the pivot node
  AVLNode * nleft = n->left;
  //nleftright is the right node of the nleft node
  AVLNode * nleftright = nleft->right;
  
  nleft->right = n;
  n->left = nleftright;
  
  //update the height fields
  n->height = max(height(n->left),height(n->right))+1;
  nleft->height = max(height(nleft->left),height(nleft->right))+1;
 
  return nleft; 
}

// private helper method for insert to allow for recursion
AVLNode* AVLTree::insert(AVLNode*& n, const string& x) {
  if (n == NULL) {
    AVLNode * output = new AVLNode();
    output->value = x;
    count++;
    return output;
  }
  else if (x.compare(n->value) < 0) {
    n->left = insert(n->left, x);
  }
  else if (x.compare(n->value) > 0) {
    n->right = insert(n->right, x);
  }
  else 
    return n;
  n->height = 1 + max(height(n->left), height(n->right));

  if(balanceFactor(n) > 1 || balanceFactor(n) <-1)
    balance(n);
  printTree();
  return n;
}

// A private helper for pathTo that will allow for recursion
void AVLTree::findPath(AVLNode* n, vector<string>& v, const string& x) const{
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


// A private helper for find that will allow for recursion
AVLNode* AVLTree::find(AVLNode* n, const string& x) const {
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


// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
 
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      count--;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      AVLNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      count--;
      return temp;
    }
    if (n->right == NULL) {
      AVLNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      count --;
      return temp;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
  return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// balance Factor returns -1,0, or 1 signaling the type of rotation needed
int AVLTree::balanceFactor(AVLNode*& n) {
  return height(n->right) - height(n->left);
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isLeft) {
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

void AVLTree::printTree() { printTree(root, NULL, false); }
