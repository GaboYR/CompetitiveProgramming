#include<bits/stdc++.h>
using namespace std;
int sum(long long x) {
    int s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }
    return s;
}
int main () {
    long long n,s;  cin >> n >> s;
    long long low = 0,high = n;
    bool exist = true;
    if (n - sum(n) < s) exist = false;
    while (high - low != 1 && exist) {
        long long mid = low + (high - low) / 2;
        if (mid - sum(mid) >= s)    high = mid;
        else low = mid;
    }
    cout << ((exist)? n - low : 0) << '\n';
    return 0;
}