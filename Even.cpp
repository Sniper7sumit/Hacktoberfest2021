#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter an integer: ";
  cin >> n;
  // Using bitwise operator to check odd/even
  if(n & 1)
     cout << n << " is odd";
  else
    cout << n << " is even";
 return 0; 
}
