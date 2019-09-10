//Derek Johnson dej3tc@virginia.edu
// 9/7/19
// List.cpp
#include <iostream>
#include "List.h"
using namespace std;
List::List(void){    // Default Constructor
	head = new ListNode;
	tail = new ListNode;
	head -> next = tail;
	tail -> previous = head;
	count = 0;
}

List::List(const List& source) {   //Copy Constructor
	head = new ListNode;
	tail = new ListNode;
	head -> next=tail;
	tail -> previous=head;
	count=0;
	ListItr iter(source.head->next);
	while (!iter.isPastEnd()) {
		insertAtTail(iter.retrieve());
		iter.moveForward();
	}
}

List::~List(void) {    //Destructor

}

List& List::operator=(const List& source) {  //Equals operator
	if (this == &source)
		return *this;
	else {
		makeEmpty();
		ListItr iter(source.head ->next);
		while (!iter.isPastEnd()) {
			insertAtTail(iter.retrieve());
			iter.moveForward();
		}
	}
	return *this;
}

bool List::isEmpty() const{  //returns true if empty
	return count == 0;
}

void List::makeEmpty() {  //Removes all items except blank head/tail
}

ListItr List::first() {  //Returns the iterator that points to the 
	ListItr * i = new ListItr(head -> next); //ListNode in the first position
	return *i;
}

ListItr List::last() {  //Returns the iterator that points to the 
	ListItr * i = new ListItr(tail -> previous); //ListNode in the last position
	return *i;
}
// Iserts x after the current iterator position
void List::insertAfter(int x, ListItr position) {
	ListNode * node = new ListNode();
	node -> value = x;
	ListNode * b = position.current;
	position.moveForward();
	ListNode * n = position.current;
	node -> next = n;
	node -> previous = b;
	b -> next = node;
	n -> previous = node;
	count ++;	
}

// Iserts x before the current iterator position
void List::insertBefore(int x, ListItr position) {
	ListNode * node = new ListNode();
	node -> value = x;
	ListNode * n = position.current;
	position.moveBackward();
	ListNode * b = position.current;
	node -> next = n;
	node -> previous = b;
	b -> next = node;
	n -> previous = node;
	count ++;	
}

// Iserts x at the tail of the list
void List::insertAtTail(int x) {
	ListNode * node = new ListNode();
	node -> value = x;
	ListNode * secondToLast = tail -> previous;
	node->next = tail;
	node->previous = secondToLast;
	secondToLast -> next = node;	
	tail -> previous = node;
	count ++;
}
//Removes the first occurrence of x
void List::remove(int x) {

}
ListItr List::find(int x) {
	ListItr l;
	return l;
}

int List::size() const {
	return 1;
}

void printList(List& source, bool direction) {
	if (direction) {
		ListItr iter = source.first();
		while (!iter.isPastEnd()) {
			cout << iter.retrieve() << ", ";
			iter.moveForward();
		}	
	}
	else {
		ListItr iter = source.last();
		while (!iter.isPastBeginning()) {
			cout << iter.retrieve() << ", ";
			iter.moveBackward();
		}
	}
	cout << endl;
}



