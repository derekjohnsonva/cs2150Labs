//Derek Johnson dej3tc
//9/24/19
//inlab4.cpp

#include <iostream>
#include <climits>
#include <sstream>
using namespace std;

int main() {
	cout << "size in bytes can be found using the prelab." << endl;
	cout << "int max= " << INT_MAX << endl;
	cout << "unsigned int max= " << UINT_MAX << endl;
	cout << "char max= " << CHAR_MAX << endl;
	int io = 0;
	int i = 1;
	unsigned int uio = 0;
	unsigned int ui = 1;
	float fo = 0.0;
	float f = 1.0;
	double doo = 0.0;
	double d = 1.0;
	char co = '0';
	char c = '1';
	bool bo = false;
	bool b = true;
	int * tt = NULL;
	char * cc = NULL;
	double * dd = NULL; //used GDB debugger to find value using x/x 
	cout << "End of the first Part of InLab" << endl << endl << endl;
	

	int IntArray[10];
	char CharArray[10];
	int IntArray2D[6][5];
	char CharArray2D[6][5];
	for(int i=0; i<sizeof(IntArray);i++) {
		IntArray[i] = i;
	}
	
	for(int i=0; i<sizeof(CharArray);i++) {
		CharArray[i] = (char) i;
	}
	for(int i=0; i<5;i++) {
		for(int j=0; j<4;j++) {
			IntArray2D[i][j] = i+j;
		}
	}
	for(int i=0; i<5;i++) {
		for(int j=0; j<4;j++) {
			CharArray2D[i][j] = (char)i+j;
		}
	}
	

	return 0;

}
