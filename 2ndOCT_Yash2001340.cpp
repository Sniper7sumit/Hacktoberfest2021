
#include <iostream>

using namespace std;

int main()
{
    int row,column;
    cin>>row>>column;
    int sum=(row+column+1)/2;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=column;j++)
        {
            if(i==j)
            {
                cout<<i;
            }
            else if(j==(sum+1-i+1)|| j==(sum+1+i-1))
            {
                cout<<j;
            }
            else{
                 cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
