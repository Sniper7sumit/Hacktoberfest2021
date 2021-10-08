#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,queries;
    cin>>n>>q;
    vector<vector<int>> arr(n);     //Creating a main vector contains reference tpo first elemnt of vector containg in each element
    for(int i=0;i<n;i++)
        int size;
        cin>>size;
        vector<int> iarr(size,0);
        for(int j=0;j<size;j++){       // Creating sub vectors for each element of main vector
            cin>>iarr[j];
        }
        arr[i]=iarr;
    }
    
    for(int i=0;i<queries;i++){            // Handling the queries
       int j,k;
        cin>>j>>k;
        cout<<arr[j][k]<<endl;
    }
    return 0;
}
