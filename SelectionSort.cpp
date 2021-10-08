#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of Array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                int t=a[j];
                a[j]=a[i];
                a[i]=t;
            }
        }
    }
    cout<<"The sorted Array\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
