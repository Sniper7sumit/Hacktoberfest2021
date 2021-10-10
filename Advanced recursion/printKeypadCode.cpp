
/* Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : The order of strings are not important.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf */
#include <iostream>
using namespace std;

void final(string *temp, int n, string output)
{
    if (n == 0)
    {
        cout << output << endl;
        return;
    }
    int last = n % 10;
    string s = temp[last];
    for (int i = 0; i < s.size(); i++)
    {
        final(temp, n / 10, s[i] + output);
    }
    if (s.size() == 0)
    {
        final(temp, n / 10, output);
    }
}

void print(int n)
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
    final(temp, n, "");
}

int main()
{
    int n;
    cin >> n;

    print(n);
    return 0;
}