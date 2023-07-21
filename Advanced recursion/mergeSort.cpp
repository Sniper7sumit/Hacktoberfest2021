/* Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 1000
Sample Input:
6 
2 6 8 5 4 3
Sample Output:
2 3 4 5 6 8 */

#include <iostream>
using namespace std;

void merge(int *a, int st, int mid, int en)
{
    int n1 = mid - st + 1;
    int n2 = en - mid;

    int l[n1];
    int r[n2];
    for (int i = 0; i < n1; i++)
    {
        l[i] = a[st + i];
    }
    for (int j = 0; j < n2; j++)
    {
        r[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0, k = st;
    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            a[k] = l[i];
            k++;
            i++;
        }
        else
        {
            a[k] = r[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        a[k] = l[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        a[k] = r[j];
        k++;
        j++;
    }
}

void mergesort(int *a, int st, int en)
{
    if (st >= en)
    {
        return;
    }
    int mid = (st + en) / 2;
    mergesort(a, st, mid);
    mergesort(a, mid + 1, en);
    merge(a, st, mid, en);
    return;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int st = 0;
    int en = n - 1;
    mergesort(a, st, en);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}