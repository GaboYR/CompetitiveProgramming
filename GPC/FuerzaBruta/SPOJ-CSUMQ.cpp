#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 2;
long long a[maxn];
int main () {
    int n;  cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (i > 0)  a[i] += a[i - 1];
    }
    int q;  cin >> q;
    while (q --) {
        int l,r;    cin >> l >> r;
        if (l > r)  swap(l,r);
        else {
            cout << a[r] - ((l != 0)?a[l - 1]:0) << '\n';
        }
    }
    return 0;
}