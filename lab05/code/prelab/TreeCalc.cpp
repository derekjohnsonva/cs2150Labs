// Derek Johnson dej3tc
// 10/7/19 
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Constructor
TreeCalc::TreeCalc() {
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
	while(!(mystack.empty()))	
		mystack.pop();
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
	while(!(mystack.empty()))
		mystack.pop();
	delete ptr;
}

bool isOperator(const string& c) {
	if (c == "/" || c=="*" || c=="-" || c =="+")
		return true;
	else return false;
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
	if (isOperator(val)) {
		TreeNode * node = new TreeNode(val);
		node->right = mystack.top();
		mystack.pop();
		node->left = mystack.top();
		mystack.pop();
		mystack.push(node);
	}
	else {
		TreeNode * n = new TreeNode(val);
		mystack.push(n);
	}
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
	if(ptr != NULL){
		cout << ptr->value<<" ";
		printPrefix(ptr->left);
		printPrefix(ptr->right); 
	}
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
	if(ptr != NULL){
		if(isOperator(ptr->value)) {
			cout <<"(";
		}
		if(ptr->left != NULL){
			printInfix(ptr->left);
			cout << " ";
		}
		cout << ptr->value;
		if(ptr->right != NULL){
			cout << " ";
			printInfix(ptr->right);		
		}
		if(isOperator(ptr->value)) {
			cout <<")";
		}
	}

}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
	if(ptr != NULL){
		printPostfix(ptr->left);
		printPostfix(ptr->right); 
		cout << ptr->value << " ";
	}

}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
	printPostfix(mystack.top());
	cout << endl;
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
        printInfix(mystack.top());
	cout << endl;
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
        printPrefix(mystack.top());
	cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
	if(ptr == NULL)
		return 0;
	if(ptr->left == NULL && ptr->right == NULL)
	return stoi(ptr->value);
	int l = calculate(ptr->left);
	int r = calculate(ptr->right);
	
	if(ptr->value == "/")
		return l/r;
	if(ptr->value == "*")
		return l*r;
	if(ptr->value == "+")
		return l+r;
	if(ptr->value == "-")
		return l-r;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    i = calculate(mystack.top());
	cleanTree(mystack.top());
	return i;
}
