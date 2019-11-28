//Derek Johnson dej3tc
//9/19/19
//prelab4.cpp

#include <iostream>
using namespace std;

void sizeOfTest() {
	cout << "The size of an int is: " << sizeof(int) << endl;
	cout << "The size of an unsigned int is: " << sizeof(unsigned int) << endl;
	cout << "The size of a float is: " << sizeof(float) << endl;
	cout << "The size of a double is: " << sizeof(double) << endl;
	cout << "The size of a char is: " << sizeof(char) << endl;
	cout << "The size of a bool is: " << sizeof(bool) << endl;
	cout << "The size of an int* is: " << sizeof(int*) << endl;
	cout << "The size of a char* is: " << sizeof(char*) << endl;
	cout << "The size of a double* is: " << sizeof(double*) << endl;
}

void outputBinary(unsigned int i) {
	int fours = 0;
	for (int t = 31; t>=0; t--) {
		if(fours ==4) {
			cout << " ";
			fours = 0;
		}
		fours ++;
		int binary = i >> t;
		if ((binary%2) == 1)
			cout << "1";
		else
			cout << "0";
	}
	cout << endl;
}

void overflow() {
	unsigned int x = 4294967295;
	cout << x+1<< endl;
	cout << "When a value type tries to store a value larger than the space it has pre alloted, it will wrap back around. In the case of an unsigned int, the value will wrap back around starting at zero which is why the output is zero. If the max value was increased by 2 the output would be 1." << endl;
}

int main() {
	cout << "Type your Number Here: " << endl;
	int x;
	cin >> x;
	sizeOfTest();
	cout << endl << endl;
	cout << "outputBinary(" << x << ")";
	outputBinary(x);
	cout << endl << endl;

	overflow();
	return 0;
}
