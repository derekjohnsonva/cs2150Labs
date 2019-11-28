//Derek Johnson
// 11/18/19
// comp.cpp
// In this program I will be writing an example main method that will
// show how the optimize tag in the compiler will change the asembly code

#include <iostream>
using namespace std;

int main() {
  const int two = 2;
  int counter = 0;
  for(int i=0; i<6;i++) {
    counter += two;
  }
  return 0;
}
