#include <iostream>
using namespace std;

int final(string *temp, int n, string *output)
{
    if (n == 0)
    {
        output[0] = "";
        return 0;
    }

    int last = n % 10;
    string s = temp[last];
    for (int i = 0; i < s.size(); i++)
    {
        int x = final(temp, n / 10, output + i);
        }
}

int ret(int n, string *output)
{
    string *temp = new string[10];
    temp[0] = "";
    temp[1] = "";
    temp[2] = "abc";
    temp[3] = "def";
    temp[4] = "ghi";
    temp[5] = "jkl";
    temp[6] = "mno";
    temp[7] = "pqrs";
    temp[8] = "tuv";
    temp[9] = "wxyz";

    int c = final(temp, n, output);
    return c;
}

int main()
{
    int n;
    cin >> n;

    string *output = new string[2000000];
    int count = ret(n, output);
    return 0;
}