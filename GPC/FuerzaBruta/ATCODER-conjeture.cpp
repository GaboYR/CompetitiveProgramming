#include<bits/stdc++.h>
using namespace std;
int main () {
    long long n;    cin >> n;
    long long res = 0;
    for (long long a = 1; a * a * a <= n; a ++) {
        for (long long b = a; a * b * b <= n; b ++) {
            long long c = n / (a * b);
            if (c >= b) {
                res += c - b + 1;
                //cout << a << " " << b << " " << c << "\n";
            }
        }
    }
    cout << res << "\n";

    return 0;
}