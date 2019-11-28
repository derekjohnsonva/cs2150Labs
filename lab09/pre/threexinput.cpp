// Derek Johnson dej3tc
// 11/14/19
// threexinput.cpp

#include <iostream>
#include <cstdlib>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int x);

int main() {
  int x, n, answer, at;
  cout << "Enter the number to pass to the Collatz Conjecture: "; 
  cin >> x;
  cout << "How many times should the operation be run? ";
  cin >> n;
  //Perform the operation the first time
  timer t;
  t.start();
  answer = threexplusone(x);
  //Perform the operation the remaining times
  for(int i = 1; i<n ;i++){
    threexplusone(x);
  }
  t.stop();
  //find the average time
  at = (t.getTime())*1000/n;
  //output the results
  cout << "Number of steps = " << answer << endl;
  cout << "Average time = " << at << endl;
  
  return 0;
}
