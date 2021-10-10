/* Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= Length of String S <= 10^3
Sample Input :
aabccba
Sample Output :
abcba */

#include <iostream>
#include <string>
using namespace std;

string rem(string s)
{
    int x = s.length();
    string ans = "";
    for (int i = 0; i < x; i++)
    {
        //ans += s[i];
        if (s[i] != s[i + 1])
        {
            ans += s[i];
        }
    }
    return ans;
}
// rec
void rem2(char *s)
{
    if (s[0] == '\0')
    {
        return;
    }
    if (s[0] == s[1])
    {
        int i = 0;
        while (s[i] != '\0')
        {
            s[i] = s[i + 1];
            i++;
        }
        rem2(s);
    }
    rem(s + 1);
}
int main()
{
    string s;
    cin >> s;
    s = rem(s);
    cout << s << endl;
    return 0;
}