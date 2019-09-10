// Derek Johnson (dej3tc)
// C++
#include <iostream>
using namespace std;

int xton(int x, int n) {
	if (n<1) {
		return 1;
	}
	else {
		return x*xton(x, n-1);
	}
}

int main() {
	int x, n, out;
	cout << "x will be raised to the power of n" << endl;
	cout << "x value: ";
	cin >> x;
	cout << "n value: ";
	cin >> n;
	out = xton(x,n);
	cout << out << endl;
	return 0;
}	

