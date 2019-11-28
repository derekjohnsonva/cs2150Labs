// Derek Johnson dej3tc@virginia.edu
// 9/7/19
// ListItr.cpp
#include <iostream>
#include "ListItr.h"
using namespace std;

//Constructor
ListItr::ListItr(void) {
	current = NULL;
}

//One parameter constructor
ListItr::ListItr(ListNode* theNode) {
	current = theNode;
}

//Returns true if past end position
bool ListItr::isPastEnd() const {
	if (current -> next == NULL) 
		return true;
	return false;
}

//Returns true if past first position
bool ListItr::isPastBeginning() const {
	if (current -> previous == NULL)
		return true;
	return false;		
}

//Advances current to next position in list
void ListItr::moveForward() {
	ListNode * forward = current -> next;
	if (!(forward == NULL))
		current = forward;
	
}
//Moves current back to previous position in list
void ListItr::moveBackward() {
	ListNode * backward = current -> previous;
	if (!(backward == NULL))
		current = backward;
}
//Returns item in current position
int ListItr::retrieve() const {
	ListNode node = *current;
	return node.value;
}
