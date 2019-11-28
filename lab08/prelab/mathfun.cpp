// mathfun.cpp
// Derek Johnson
// 11/4/2019

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int product(int x, int y);
extern "C" int power(int x, int y);

int main() {
  int x, y, prod, pow;
  cout << "Enter the first number:  ";
  cin >> x;
  cout << "Enter the second number:  ";
  cin >> y;
  // Find the product of the two numbers
  prod = product(x,y);
  // find the power of the two numbers
  pow = power(x,y);
  cout << "the product is " << prod << " and the power is " << pow << endl;
  
  return 0;
}
