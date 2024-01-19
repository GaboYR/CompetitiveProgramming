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
ll merge(vi &L,vi &R) {
    reverse(L.begin(),L.end());
    for (int i = 1; i < sz(L); i ++)    L[i] = max(L[i],L[i - 1]);
    for (int i = 1; i < sz(R); i ++)    R[i] = max(R[i],R[i - 1]);
    ll res = 0;
    int ind = 0;
    for (auto x : L) {
        while (ind < sz(R) and R[ind] <= x) ind ++;
        res += 1ll * x * ind;
    }
    ind = 0;
    for (auto x : R) {
        while (ind <  sz(L) and L[ind] < x) ind ++;
        res += 1ll * x * ind;
    }
    return res;
}
ll solve(vi &v){
    if (sz(v) == 1) return v[0];
    int mid = sz(v) / 2;
    vi L(v.begin(),v.begin() + mid),R(v.begin() + mid,v.end());
    ll res = solve(L) + solve(R);
    return res + merge(L,R);
}
int main(){
    fast_io
    int n;  cin >> n;
    vi v(n);
    for (int i = 0; i < n; i ++) cin >> v[i];
    ll ans = solve(v);
    for (auto &e:v) e = -e;
    cout << ans + solve(v) << "\n";
    return 0;
}