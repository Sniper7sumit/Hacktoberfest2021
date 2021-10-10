#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
   if (n < 2) return false;
   for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) return false;
   }
   return true;
}
bool isPalindrome(int n) {
   int num, digit, rev = 0;
   n = num;
   while (num) {
      digit = num % 10;
      rev = (rev * 10) + digit;
      num = num / 10;
   }
return n == rev ? true : false;
}
int getNextSmallestPrimePalindrome(int n) {
   int i = n + 1;
   while (true) {
      if (isPrime(i) && isPalindrome(i)) {
         return i;
      }
      i += 1;
   }
}
int main() {
   int N = 15;
   cout << getNextSmallestPrimePalindrome(N) << endl;
   return 0;
}