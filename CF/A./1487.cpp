#include<bits/stdc++.h>
using namespace std;
int square_root(long long n)
{
    long long low = 1,high = 1e8;
    while (high - low != 1)
    {
        long long mid = low + (high - low) / 2;
        if (mid * mid <= n)  low = mid;
        else high = mid;
    }
    return low;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;  cin >> testCases;
    while (testCases -- )
    {
        int n;  cin >> n;
        int root = square_root(2 * n - 1);
        cout << (root - 1) / 2 << '\n';
    }
    return 0;
}
