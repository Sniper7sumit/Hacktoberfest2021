#include <bits/stdc++.h>
using namespace std;

int change(char x, char y)
{
    if (x == y)
        return 0;
    return 2;
}

int stringEdit(string x, string y)
{
    int n = x.length();
    int m = y.length();
    int c[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0)
                c[i][j] = j;
            else if (j == 0)
                c[i][j] = i;
            else if (x[i - 1] == y[j - 1])
                c[i][j] = c[i - 1][j - 1];
            else
                c[i][j] = min(1 + c[i][j - 1], min(1 + c[i - 1][j], c[i - 1][j - 1] + change(x[i - 1], y[j - 1])));
        }
    }
    return c[n][m];
}

int main()
{
    //	ios_base::sync_with_stdio(false);
    //	cin.tie(NULL);
    string x, y;
    cout << "Enter String X: ";
    cin >> x;
    cout << "Enter String Y: ";
    cin >> y;
    cout << "Cost Of converting X into Y : " << stringEdit(x, y) << endl;

    return 0;
}
