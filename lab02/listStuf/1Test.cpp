//Derek Johnson dej3tc@virginia.edu
// 9/7/19
// List.cpp
#include <iostream>
#include "List.h"
using namespace std;

int main() {
	List x;
	cout << "build List called x" << endl;
	cout << "Is List Empty?... " << x.isEmpty() << endl;
	x.insertAtTail(5);
	cout << "Is List Empty?... " << x.isEmpty() << endl;
	printList(x, 1);
	x.insertAtTail(4);
	printList(x, 1);
	printList(x,0);
		
	return 0;
}
