#include<bits/stdc++.h>
using namespace std;
const int maxn = 3002;
int x[maxn],y[maxn];
bool t[2001][2001];
int main () {
    int n;  cin >> n;
    for (int i = 0;i < n; i ++) {
        cin >> x[i] >> y[i];
        t[x[i] + 1000][y[i] + 1000] = 1;
    }
    long long res = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if ((x[i] + x[j]) % 2 == 0 && (y[i] + y[j]) % 2 == 0) {
                res += t[(x[i] + x[j]) / 2 + 1000][(y[i] + y[j])/2 + 1000];
            }
        }
    }
    cout << res << '\n';
}