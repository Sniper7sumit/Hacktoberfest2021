#include<iostream>
using namespace std;
int main(){
    int a[100];
    int n;
    cout<<"Enter the  number of elements in an array";
    cin>>n;
    cout<<"Enter the  elements in an array";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=0;
    for(int i=0;i<n;i++){
        for ( int j=i+1;j<n;j++){
            if (a[i]>a[j])
            c++;
        }
    }
    cout<<"The number of inversions required are ";
    cout<<c<<" "<<endl;
    return 0;
}
