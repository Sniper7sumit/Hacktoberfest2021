#include<bits/stdc++.h>
using namespace std;

int find(vector<int> v,int n){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]>v[mid-1] and v[mid]>v[mid+1])
            return mid;
        else if(v[mid]<v[mid-1] and v[mid]>v[mid+1])
            high=mid-1;
        else if(v[mid]>v[mid-1] and v[mid]<v[mid+1])
            low=mid+1;
    }
    return -1;
}

int asc(vector<int> v,int n,int low,int high,int k){
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]==k)
            return mid;
        else if(v[mid]>k)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int desc(vector<int> v,int n,int low,int high,int k){
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]==k)
            return mid;
        else if(v[mid]>k)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

int check(vector<int> v,int n,int maxi,int k){
    if(v[maxi]==k)
        return maxi;
    else if(v[maxi]<k)
        return -1;
    else{
        int ans=asc(v,n,0,maxi,k);
        if(ans!=-1)
            return ans;
        return desc(v,n,maxi,n-1,k);    
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.push_back(k);
    }
    int key;
    cin>>key;
    int maxi=find(v,n);
    cout<<check(v,n,maxi,key);
}
