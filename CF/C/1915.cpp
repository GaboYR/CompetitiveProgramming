#include<bits/stdc++.h>
using namespace std;
long long f(long long v) {
    long long low = 1,high = 2e9;
    while (high - low > 1) {
        long long mid = low + (high - low) / 2;
        if (mid * mid > v) high = mid;
        else low = mid + 1;
    }
    if (low * low > v)  low --;
    return low;
}
int main () {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC; cin >> TC;
    while (TC --) {
        int len;    cin >> len;
        long long sum = 0;
        while (len --) {
            int v;  cin >> v;
            sum += v;
        }
        cout << ((f(sum) * f(sum) == sum)? "YES":"NO") << '\n';
    }
}