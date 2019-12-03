// binHeapNode.h

// Derek Johnson, dej3tc
// 11/24/19

#ifndef BINHEAPNODE_H
#define BINHEAPNODE_H
#include <string>
using namespace std;
class binHeapNode{
  public:
    binHeapNode();
    ~binHeapNode();
    char letter;
    unsigned int freq;
    binHeapNode* left;
    binHeapNode* right;  
};


#endif
