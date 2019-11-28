/* linkedlist.c 
  Derek Johnson dej3tc
  11/20/19
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int number;
  struct Node *next;
};

struct Node* push(struct Node* start, int x){
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->number = x;
  newNode->next = start;
  return newNode;
}

void printList(struct Node* start){
  if(start == NULL){
    return;
  }
  printList(start->next);
  printf("%d \n", start->number);
  free(start);
}

int main() {
  int n;
  printf("Enter how many values o input: ");
  scanf("%d", &n); 
  struct Node* start = NULL;
  for(int i =0; i<n ; i++) {
    int val;
    printf("Enter value %d: ",i+1);
    scanf("%d", &val);
    
    start = push(start, val);
  }  
  printList(start);
  free(start);
}


