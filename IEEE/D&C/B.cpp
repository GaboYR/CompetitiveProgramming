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
map<int,int> p,q;
ll cont = 0;
ll res = 0;
ll merge(vi &L,vi &R) {
    int i = 0,j = 0;
    while (i < sz(L) and j < sz(R)) {
        if (L[i] > R[j]) {

        }
    }
}
ll solve(vi &v) {
    if (sz(v) == 1) return 0;
    int mid = sz(v)/2;
    vi L(v.begin(),v.begin() + mid);
    vi R(v.begin() + mid,v.end());
    res += solve(L) + solve(R);
    return res + merge(L,R);
}
int main(){
    fast_io
    int n;  cin >> n;
    vi v(n),contL(n),contR(n);
    for (int i = 0; i < n; i ++)    cin >> v[i];
    for (int i = 0; i < n; i ++) {
        contL[i] = ++ p[v[i]];
        contR[n - i - 1] = ++ q[v[n - i - 1]];
    }
    ll ans = 0;
    // for (int i = 0; i < n; i ++) {
    //     if (contL[i] == 1)  continue;
    //     else {
    //         for (int j = n - 1; j > i;j --) {
    //             if (contR[j] < contL[i])    ans ++;
    //         }
    //     }
    // }
    res = solve(contL,contR);
    cout << res - exc<< "\n";
    return 0;
}