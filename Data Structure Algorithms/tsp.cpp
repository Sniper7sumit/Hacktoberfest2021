//Travelling salesman problem

#include<iostream>
using namespace std;
int ary[10][10], completed[10], n, cost = 0;
void takeInput (){
  int i, j;
  cout << "Enter the number of nodes: ";
  cin >> n;
  cout << "\nEnter the Cost Matrix\n";
  for (i = 0; i < n; i++){
      cout << "\nEnter Elements of Row " << i + 1 << ":\n";
      for (j = 0; j < n; j++)
        cin >> ary[i][j];
      completed[i] = 0;
    }
  cout << "\n\nThe cost list is:";
  for (i = 0; i < n; i++){
      cout << "\n";
      for (j = 0; j < n; j++)
	cout << "\t" << ary[i][j];
    }
}
int least (int c){
  int i, nc = 999;
  int min = 999, kmin;
  for (i = 0; i < n; i++){
      if ((ary[c][i] != 0) && (completed[i] == 0)&& (ary[c][i]!=10000))
	    if (ary[c][i] + ary[i][c] < min){
    	    min = ary[i][0] + ary[c][i];
    	    kmin = ary[c][i];
    	    nc = i;
	  }
    }
  if (min != 999)
    cost += kmin;
  return nc;
}
void mincost (int p){
  int i, npp;
  completed[p] = 1;
  cout << p + 1 << "--->";
  npp = least (p);
  if (npp == 999){
      npp = 0;
      cout << npp + 1;
      cost += ary[p][npp];
      return;
    }
  mincost (npp);
}
int main (){
  takeInput ();
  cout << "\n\nThe Path is:\n";
  mincost (0);
  cout << "\n\nMinimum cost is " << cost;
  return 0;
}
