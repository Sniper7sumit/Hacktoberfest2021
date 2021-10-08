
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
   Contributor:Ankit Bhujeja
   Problem statement: https://www.hackerrank.com/challenges/vector-erase/problem?isFullScreen=true

*/

int main() {
    
    int n,element;
    vector<int> vec;
    cin>>n;                           //taking length of a vector
    for(int i=0;i<n;i++){
          cin>>element;                     //Taking elements of vector
          vec.push_back(element);
     }
      int a,b,c;
      cin>>a;
      vec.erase(vec.begin()+a-1);      //Remove the (a-1)th index element or ath element from vector 
      
      cin>>b>>c;
      vec.erase(vec.begin()+b-1,vec.begin()+c-1);     // Removing all elements falling in range of b and c
      cout<<vec.size()<<endl;
      for(int i=0;i<vec.size();i++){
          cout<<vec[i]<<" ";               //printing the vector
      }
    return 0;
}
