#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,d=0,f=1;
        cin>>n;
        int a[n], b[n];
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        for(int i=1; i<=n; i++)
        {
            cin>>b[i];
        }
        for(int i=1; i<=n-2; i++)
        {
            if(a[i]<b[i] || a[i]==b[i])
            {
                d=b[i]-a[i];
                a[i]=a[i]+d;
                a[i+1]=a[i+1]+(2*d);
                a[i+2]=a[i+2]+(3*d);
            }
            else
            {
                f=0;
                break;
            }
        }
        if(f!=1 || a[n]!=b[n] || a[n-1]!=b[n-1])
        cout<<"NIE"<<"\n";
        else
        cout<<"TAK"<<"\n";
    }
	return 0;
}
