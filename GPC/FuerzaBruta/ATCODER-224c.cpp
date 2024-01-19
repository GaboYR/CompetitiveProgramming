#include<bits/stdc++.h>
using namespace std;
const int maxn = 302;
int x[maxn],y[maxn];
bool triangle(int i,int j,int k) {
    return (y[k] - y[j]) * (x[j] - x[i]) != (y[j] - y[i]) * (x[k] - x[j]);
}
int main () {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;  cin >> n;

    for (int i = 0; i < n; i ++)    cin >> x[i] >> y[i];

    long long res = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            for (int k = j + 1; k < n; k ++) {
                res += triangle(i,j,k);
            }
        }
    }
    cout << res << "\n";
    return 0;
}