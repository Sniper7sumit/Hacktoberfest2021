#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v {50,100,20,400,500,200,750};
    cout << *max_element(v.begin(), v.end());
    return 0;

}
