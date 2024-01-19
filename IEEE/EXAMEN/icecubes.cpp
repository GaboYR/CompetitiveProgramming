#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define cin std::cin
#define cout std::cout
using ll = long long;
using ld = long double;
using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;
int a[1000][1000],dp[1000][1000];
int n,m,k,b;
void print(){
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
int solve() {
    int contB = 0;
    for (int i = 0; i < m - 1; i ++) {
        a[0][i + 1] += a[0][i];
    }
    for (int i = 0; i < n - 1; i ++) {
        a[i + 1][0] += a[i][0];
    }
    for (int i = 1; i < n; i ++) {
        for (int j = 1; j < m; j ++) {
            a[i][j] += max(a[i - 1][j],a[i][j - 1]);
        }
    }
    return a[n - 1][m - 1];
}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        cin >> n >> m >> k >> b;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++)    cin >> a[i][j];
        }
        print();
        solve();
        print();
    }
    return 0;
}