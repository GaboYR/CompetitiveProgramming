#include<bits/stdc++.h>
using namespace std;
const int maxn = 45;
long long l[maxn],r[maxn];
long long L[maxn];
int main ()
{
    int testCases;  cin >> testCases;
    while (testCases -- )
    {
        int n,c,q;  cin >> n >> c >> q;
        string s;   cin >> s;  
        L[0] = n;
        for (int i = 1; i <= c; i ++)
        {
            cin >> l[i] >> r[i];
            L[i] = L[i - 1] + (r[i] - l[i] + 1);
        }
        while (q --)
        {
            long long k;    cin >> k;
            for (int i = c; i >= 1; i --)
            {
                if (k > L[i - 1])
                {
                    k -= (L[i - 1] - l[i] + 1);
                }
            }
            cout << s[k - 1] << '\n';
        }
    }
}