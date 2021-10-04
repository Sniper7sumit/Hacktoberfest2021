#include<bits/stdc++.h>
using namespace std;
 
int KadaneAlgo(int arr[], int n)
{
    int max = INT_MIN, max_end = 0;
 
    for (int i = 0; i < n; i++)
    {
        max_end = max_end + arr[i];
        if (max < max_end)
            max = max_end;
 
        if (max_end < 0)
            max_end = 0;
    }
    return max;
}
 
int main()
{
    int arr[] = {-3,21,16,-22,3,-2,55,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_sum = KadaneAlgo(arr, n);
    cout << "max sum : " << max_sum;
    return 0;
}
