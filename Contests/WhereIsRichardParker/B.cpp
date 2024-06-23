#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i ++) cin >> a[i];
    int sum[m] = {0};
    int d;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> d;
            sum[j] += d;
        }
    }
    for (int i = 0; i < m; i ++) {
        if (sum[i] < a[i]) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}