//Derek Johnson dej3tc
//9/15/19
//testPostfixCalc.cpp

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include "postfixCalculator.h"
using namespace std;

int main() {
	string s;
	PostfixCalculator p;
	List * l = new List();
	l->push(1);
	l->push(2);
	cout << l->top() << endl;
	cout << "Type your expression to be evaluated in one line with characters seperated by spaces then hit enter" << endl;
	while (cin >> s) {
		//char cstr[s.size() +1];
		//strcpy(cstr, s.c_str());
		int i = atoi(s.c_str());
		if (s == "+")
			p.add();
		else if (s == "-")
			p.subtract();
		else if (s == "*")
			p.multiply();
		else if (s == "/")
			p.divide();
		else if (s == "~")
			p.negate();

		else if( !(i==0) || s == "0")  {
			p.pushNum(i);
		}	

	}
	
	cout << p.getTop() << endl;
	return 0;
}
	
