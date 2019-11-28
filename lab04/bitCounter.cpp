//Derek Johnson dej3tc
//9/26/19
//bitCounter.cpp

#include <iostream>
#include <cstdlib>
#
using namespace std;

int numOfOnes(int n) {
	if (n == 0) return 0;
	if(n % 2 == 0) {
		return numOfOnes(n/2);
	}
	else {
		return 1 + numOfOnes(n/2);
	}
}

int main(int argc, char* argv[]) {
	int i = atoi(argv[1]);
	int number = numOfOnes(i);
	cout << "The number of 1s in the binary representation of "
	     << i << " is " << number << endl;
	return 0;
}

