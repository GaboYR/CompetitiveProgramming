/*
    Link : https://codeforces.com/contest/255/problem/D
*/
#include<bits/stdc++.h>
using namespace std;
long long x,y,n,c;
long long calc(long long a,long long b,long long t)
{
    long long mx = max(a,b);
    long long mn = min(a,b);
    if (t <= mn)                            return (t * t + t) / 2;
    else if (t > mn && t <= mx)             return (mn * mn + mn) / 2 + (t - mn) * mn;
    else if (t > mx && t <= mx + mn - 1)    return (mn * mn + mn) / 2 + (mx - mn) * mn + mn * (t - mx) - (t - mx) * (t - mx + 1) / 2;
    else return mn * mx;
}
long long f(long long m)
{
    long long ru = calc(n - x + 1,n - y + 1,m + 1);
    long long lu = calc(x - 1,n - y + 1,m);
    long long ld = calc(x - 1,y - 1,m - 1);
    long long rd = calc(n - x + 1,y - 1,m);
    return ru + lu + ld + rd;
}
int main ()
{
    cin >> n >> x >> y >> c;
    long long low = 0,high = 2 * n + 1;
    while (high - low != 1)
    {
        int mid = low + (high - low) / 2;
        if (f(mid) >= c) high = mid; 
        else low = mid;
    }
    if (f(low) < c) cout << high;
    else cout << low;
    return 0;
}
