// Derek Johnson, dej3tc
// 11/24/2019

// heap.cpp
#include "heap.h"
#include "binHeapNode.h"
#include <vector>
using namespace std;
// default constructor
BinaryHeap::BinaryHeap() : heap_size(0){
  heap.push_back(0);
}

//builds a heap from an unsorted vector
BinaryHeap::BinaryHeap(vector<binHeapNode *> vec) :
    heap_size(vec.size()) {
  heap = vec;
  heap.push_back(heap[0]);
  heap[0] = 0;
  for ( int i = heap_size/2; i > 0; i--)
    percolateDown(i);
}
//destructor
BinaryHeap::~BinaryHeap(){
}

// insert
void BinaryHeap::insert(binHeapNode* n){
  heap.push_back(n);
  percolateUp(++heap_size);
}

unsigned int BinaryHeap::size(){
  return heap_size;
}

bool BinaryHeap::isEmpty(){
  if(heap_size <= 1) return true;
  return false;
}

binHeapNode* BinaryHeap::getNode(int i){
  return heap[i];
}

binHeapNode* BinaryHeap::deleteMin(){
  if ( heap_size == 0 )
    throw "deleteMin() called on empty heap";
  binHeapNode* ret = heap.at(1);
  heap.at(1) = heap.at(heap_size--);
  heap.pop_back();
  percolateDown(1);
  return ret;
}

void BinaryHeap::percolateUp(int hole){
  binHeapNode* x = heap[hole];
  //check if at root or the frequency is greater than the parent
  for ( ; (hole > 1) && ((x->freq) < (heap.at(hole/2)->freq)) ; hole /=2 ) {
    heap.at(hole) = heap.at(hole/2);
  }
  heap[hole] = x;
}

void BinaryHeap::percolateDown(int hole){
  binHeapNode* x = heap.at(hole);
  while ( hole*2 <= heap_size ) {
    int child = hole*2;
    if((child+1 <= heap_size) && 
      (heap.at(child+1)->freq < heap.at(child)->freq))
       child ++;
    if( x->freq > heap.at(child)->freq) {
      heap.at(hole) = heap.at(child);
      hole = child;  
    }
    else break;
    
  }
  heap.at(hole) = x;
}



