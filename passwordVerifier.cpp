#include<iostream>


using namespace std;
int main()
{
    string pass;
    getline(cin,pass);
    int lower=0, upper =0, number =0, special =0;
    int size = pass.length();
    for(int i =0; i<size; i++)
    {
        if(pass[i]>= 'A' && pass[i] <= 'Z')
        {upper++;}
        else if(pass[i]>= 'a' && pass[i] <= 'z')
        {lower++;}
        else if(pass[i] >= '0' && pass[i]<= '9')
        {number++;}
        else
        {special++;}
    }

    if(lower>0 && upper>0 && special>0 && number>0)
    {
        cout<<"Valid Password";
    }
    else
    {
          cout<<"Invalid password";
    } 
    return 0;

}
