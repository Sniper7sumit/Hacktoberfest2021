#include<iostream>
#include<stack>
#include<vector>
using namespace std;

    vector<long long> next_greater_element(vector<long long> arr, int n){
        vector<long long>v(n,-1);
        stack<long long>st;
        for(int i=0;i<n;++i)
        {
            if(st.empty())
            {
                st.push(i);
            }
            if(arr[i]<arr[st.top()])
            {
                st.push(i);
            }else{
            while(!st.empty() && arr[st.top()]<arr[i])
            {
                v[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        }
        return v;
    }


int main()
{
    int n;
    cin>>n;
    vector<long long>v(n);
    //taking input from user
    for(int i=0;i<n;i++)
        cin>>v[i];

    vector <long long>result = next_greater_element(v, n);
    //printing result
    for (long long i : result)
    {
        cout << i << " ";
    }
    cout<<endl;
	return 0;
}