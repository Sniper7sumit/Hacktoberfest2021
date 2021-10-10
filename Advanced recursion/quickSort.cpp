/* Sort an array A using Quick Sort.
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

int partition(int *a, int st, int en)
{
    int pivot = a[en];
    int i = st - 1;
    for (int j = st; j < en; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[en];
    a[en] = a[i + 1];
    a[i + 1] = temp;
    return i + 1;
}

void quicksort(int *a, int st, int en)
{
    if (st >= en)
    {
        return;
    }
    int p = partition(a, st, en);
    quicksort(a, st, p - 1);
    quicksort(a, p + 1, en);
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
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}