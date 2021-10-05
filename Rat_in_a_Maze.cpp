#include <iostream>
using namespace std;
bool maze(int **arr, int p, int q, int n)
{
    if (p < n && q < n && arr[p][q] == 1)
        return true;
    return false;
}

bool rat(int **arr, int p, int q, int n, int **solarr)
{
    if (p == n - 1 && q == n - 1)
    {
        solarr[p][q] = 1;
        return true;
    }

    if (maze(arr, p, q, n))
    {
        solarr[p][q] = 1;
        if (rat(arr, p + 1, q, n, solarr))
            return true;
        if (rat(arr, p, q + 1, n, solarr))
            return true;
        solarr[p][q] = 0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    int **solarr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solarr[i] = new int[n];
        for (int j = 0; j < n; j++)
            solarr[i][j] = 0;
    }
    if (rat(arr, 0, 0, n, solarr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << solarr[i][j] << " ";
            cout<<endl;
        }
    }
    return 0;
}
