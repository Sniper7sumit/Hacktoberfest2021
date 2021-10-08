#include<bits/stdc++.h>
using namespace std;
class kmp // KMP substring searching algorithm
{
    public:
    void lps_array(char *pat, int m, int *lps)
    {
        int len = 0;
        int i = 1;
        lps[0] = 0;
        while (i < m)
        {
            if (pat[len] == pat[i])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    vector<int> pattern_search(char *txt, char *pat)
    {
        int m = strlen(pat);
        int n = strlen(txt);
        int lps[m];
        int i = 0, j = 0;
        vector<int> matches;
        lps_array(pat, m, lps);
        while (i < n)
        {
            if (pat[j] == txt[i])
            {
                i++;
                j++;
            }
            if (j == m)
            {
                matches.emplace_back(i - j);
                j = lps[j - 1];
            }
            else if (i < n && pat[j] != txt[i])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return matches;
    }
};