/*

Author : Puneet Goel
Code: Segment tree for sum queries

*/

#include<bits/stdc++.h> 
using namespace std;

//construct the sum segment tree from the input array
void construct(int *tree, int a[], int s, int e, int i){  
    if(s==e) { 
        tree[i] = a[s-1]; 
        return; 
    }

    int mid = (s+e)/2; 
    construct(tree,a,s,mid,2*i); 
    construct(tree,a,mid+1,e,2*i+1);

    tree[i]=tree[2*i]+tree[2*i+1]; 
}


//update the segment tree
void update(int *tree, int l, int r, int j, int i, int c){   
    if(j<l || j>r) 
        return;

    tree[i]+=c;  

    if(l==r) 
        return; 

    int mid = (l+r)/2; 
    update(tree,l,mid,j,2*i,c); 
    update(tree,mid+1,r,j,2*i+1,c); 
}

// find the sum from segment tree within a given range
int sum(int *tree, int l, int r, int s, int e, int i){  
    if(l<=s && r>=e) 
        return tree[i]; 
   
    if(r<s || l>e) 
        return 0; 
  
    int mid = (s+e)/2; 
    return sum(tree,l,r,s,mid,2*i) + sum(tree,l,r,mid+1,e,2*i+1); 
}


int main()
{
    int n, queries; 
    cin >> n >> queries;  
    
    int a[n]; 
    
    //array input 
    for(int i=0;i<n;i++){
        cin >> a[i]; 
    }

    //dynamic allocation for segment tree
    int *tree = new int[4*n+4];    
    construct(tree,a,1,n,1); 

   
    for(int i=0; i<queries; i++){
        //two types of queries 1. update 2. print sum 
        // query input x l r 
        // if x == 1, update query where l means index and r is new value,
        // if x == 2, sum query find sum of range from l to r-1

        int x, l ,r;
        cin >> x >> l >> r; 

        if(x == 1){
            update(tree,1,n,l+1,1,r-a[l]);
            a[l] = r;
        }else{
            int ans = sum(tree,l+1,r,1,n,1);
            cout<< ans << endl;
        }
    }
   
	return 0;
}


/*

Input : 
5 5
1 2 3 4 5 
1 0 4 
2 0 5 
1 1 4
1 3 5
2 2 5

Output : 
18
13
*/