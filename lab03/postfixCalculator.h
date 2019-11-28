//Derek Johnson dej3tc
//9/15/19
//postfixCalculator.h
#ifndef POSTFIX_H
#define POSTFIX_H
#include <iostream>
#include <cstdlib>
#include <stack>
#include "list.h"
using namespace std;

class PostfixCalculator {
	public:
		PostfixCalculator();
		void add();
		void subtract();
		void divide();
		void multiply();
		void negate();
		int getTop();
		void pushNum(int x);
		void clearStack();		
		void push(int x);
		void pop();
	private:
		friend class List;
		List * nums; //The stack of numbers being operated upon
};		

#endif
