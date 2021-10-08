#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int i,num;
    cout<<"Print all odd numbers until\n";
    cin>>num;
    cout<<"Odd numbers from 1 to"<<num<< are\n";
    for(i=1; i<=num; i++){
        if(i%2==1)
        {
            cout<<i<<"\n";
        }
    }
getch();
    return 0;
}
