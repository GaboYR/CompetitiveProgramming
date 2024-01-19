#include<bits/stdc++.h>
using namespace std;

int main () {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;  cin >> n;
    long long res = 0;
    for (int i = 1; i <= n; i ++) {
        res += ((n - 1)/i);
    }
    cout << res << '\n';
    return 0;
}