#include<bits/stdc++.h>
using namespace std;
int main () {
    int n;  cin >> n;
    long long res = 0;
    for (long long a = 1; a <= n; a ++) {
        for (long long b = 1; a * b <= n; b ++) {
            for (long long c = 1; a *b * c <= n; c ++) {
                res ++;
            }
        }
    }
    cout << res << '\n';
    return 0;
}