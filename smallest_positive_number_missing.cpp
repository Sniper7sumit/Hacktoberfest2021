#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],maximum=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maximum=max(maximum,a[i]);
    }
    int b[maximum];
    for(int i=0;i<maximum;i++){
        b[i]=-1;
    }
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            b[a[i]]=i;
        }
    }
    for(int i=0;i<maximum;i++){
        if(b[i]==-1){
            cout<<i;
            break;
        }
    }
}
