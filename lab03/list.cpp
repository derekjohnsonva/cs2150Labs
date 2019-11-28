//Derek Johnson dej3tc@virginia.edu
// 9/7/19
// list.cpp
#include <iostream>
#include "list.h"
using namespace std;
List::List(void){    // Default Constructor
	head = new ListNode;
	tail = new ListNode;
	head -> next = tail;
	tail -> previous = head;
	count = 0;
}

List::List(const List& source) {   //Copy Constructor
	head = new ListNode;    //If calling this method multiple times, set the iterator between each 
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
	this->makeEmpty();
	delete head;
	delete tail; 
}

List& List::operator=(const List& source) {  //Equals operator
	if (this == &source)  //If calling this method multiple times, set the iterator between each 
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
	ListItr iter(this->first());
	while (!iter.isPastEnd()) {
		delete iter.current;
		iter.moveForward();
	}
	head -> next = tail;
	tail -> previous = head;
	this -> count = 0;
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
	ListItr iter(this->first());
	while (!iter.isPastEnd()) {
		if (iter.current->value == x){
			ListNode * p = iter.current->previous;
			ListNode * n = iter.current->next;
			delete iter.current;
			p -> next = n;
			n -> previous = p;
			this -> count --;
			break;
		}
		iter.moveForward();
	}
}
ListItr List::find(int x) {
	ListItr * iter = new ListItr((this->first()));
	while (!iter->isPastEnd()) {
		if (iter->current->value == x){
			return *iter;
		}
		iter->moveForward();
	}
	return *iter;
}

int List::size() const {
	return count;
}

void List::push(int x) {
	ListItr * iter = new ListItr(this->first());
	this->insertBefore(x, *iter);
}

void List::pop() {
	ListItr * iter = new ListItr(this->first());
	ListNode * p = iter->current->previous;
	ListNode * n = iter->current->next;
	delete iter->current;
	p-> next = n;
	n -> previous =p;
	this -> count --;
}

int List::top() {
	ListItr * iter = new ListItr(this->first());
	return iter->current->value;	
}

void printList(List& source, bool direction) {
	if (direction) {
		ListItr iter = source.first();
		while (!iter.isPastEnd()) {
			cout << iter.retrieve() << " ";
			iter.moveForward();
		}	
	}
	else {
		ListItr iter = source.last();
		while (!iter.isPastBeginning()) {
			cout << iter.retrieve() << " ";
			iter.moveBackward();
		}
	}
	cout << endl;
}



