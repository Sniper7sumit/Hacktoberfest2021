#include <bits/stdc++.h>
using namespace std;

bool triplet(int a, int b, int c)
{
    int d = max(a, max(b, c));
    int x, y;
    if (d == a)
    {
        x = b;
        y = c;
    }
    else if (d == b)
    {
        x = a;
        y = c;
    }
    else
    {
        x = a;
        y = b;
    }

    if (d * d == x * x + y * y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    cout << triplet(a, b, c);

    return 0;
}
