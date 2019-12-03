// Derek Johnson, dej3tc
// 11/24/2019
// heap.h

#ifndef HEAP_H
#define HEAP_H
#include "binHeapNode.h"
#include <vector>
using namespace std;
class BinaryHeap {
  public:
    BinaryHeap();
    BinaryHeap(vector<binHeapNode *> vec);
    ~BinaryHeap();
    void insert(binHeapNode* n);
    unsigned int size();
    bool isEmpty();
    binHeapNode* getNode(int i);
    binHeapNode* deleteMin();
  private:
    vector<binHeapNode *> heap;
    unsigned int heap_size;
    void percolateUp(int hole);
    void percolateDown(int hole);
};


#endif 
