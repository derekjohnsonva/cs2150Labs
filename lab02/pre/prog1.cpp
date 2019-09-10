#include <iostream>
using namespace std;

void my_subroutine() {
	cout << "Hello world" << endl;
}

int main() {
	int x = 4;
	int *p = NULL;
	my_subroutine();
	cout << x << ", "<< *p << endl;
	return 0;
}

