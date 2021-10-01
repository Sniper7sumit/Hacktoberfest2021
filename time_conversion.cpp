//Program for Time_Conversion in C++
//Returns the time by converting the input string into the 24hour format

#include <iostream>
#include <algorithm>
#include <vector>
#include <string> 

using namespace std;

int main()
{
    string s;
    cin>>s;
    int h= stoi(s.substr(0,2));
    char x = s.at(8);
    if(x=='A'){ //checks if it is AM
        if(h==12){
            cout<< ("00" + s.substr(2,6));
        }
        else{
            cout<< (s.substr(0,8));
        }   
    }
    else{ //for PM
        if(h==12){
            cout<< (s.substr(0,8));
        }
        else{
            cout<< (to_string(h+12) + s.substr(2,6)); //adds 12 to get the time in the 24hour format
        }
    }
    return 0;
}
