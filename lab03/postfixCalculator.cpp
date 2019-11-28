//Derek Johnson dej3tc
//9/15/19
//postfixCalculator.cpp
#include <cstdlib>
#include <stack>
#include <iostream>
#include "postfixCalculator.h"
#include "list.h"
using namespace std;

PostfixCalculator::PostfixCalculator(void) {
	nums = new List();
}

int PostfixCalculator::getTop() {
	int output = nums->top();
	nums->pop();
	return output;
}

void PostfixCalculator::add() {
	int y = this->getTop();
	int x = this->getTop();
	int output = x+y;
	nums->push(output);
}

void PostfixCalculator::subtract() {
	int y = this->getTop();
	int x = this->getTop();
	int output = x-y;
	nums->push(output);
}

void PostfixCalculator::multiply() {
	int y = this->getTop();
	int x = this->getTop();
	int output = x*y;
	nums->push(output);
}

void PostfixCalculator::divide() {
	int y = this->getTop();
	int x = this->getTop();
	int output = x/y;
	nums->push(output);
}

void PostfixCalculator::negate() {
	int x = this->getTop();
	int output = 0-x;
	nums->push(output);
}

void PostfixCalculator::pushNum(int x) {
	nums->push(x);
}
void PostfixCalculator::clearStack() {
	while(!(this->nums->isEmpty()))
		this->nums->pop();
}
void PostfixCalculator::push(int x) {
	this->nums->push(x);
}
void PostfixCalculator::pop() {
	this->nums->pop();
}

