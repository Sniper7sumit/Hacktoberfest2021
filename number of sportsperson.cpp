// There are n number of sportspersons and each of their induvial scores are also given.They are stuck between two pillars. Each pillar has a strength. A sportsperson can 
//  come out only if he/she breaks both the pillars.Only one pillar can be broken at a time. A pillar can be broken only if its strength is a multiple of the score of the 
//  sportsperson. We have to find the number of sportspersons who can come out of the pillars. 

//  Input: N number of sprtspersons Scores of sportspersons Strength of pillars 

//  Output: number of sportspersons who can come out of the pillars

//  This is the question

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,p,q,c=0;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  cin>>p>>q;
  for(int i=0; i<n; i++)
  {
    if(p%a[i]==0 && q%a[i]==0 )
      c=c+1;
  }
  cout<<c;
    return 0;
}
