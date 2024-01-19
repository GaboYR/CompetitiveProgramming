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
int cont = 0;
vi merge(vi &L, vi &R){
    vi res;
    if (L[0] > R[0]) {
        cont ++;
        for (auto e:R)  res.emplace_back(e);
        for (auto e:L)  res.emplace_back(e);
    }
    else {
        for (auto e:L)  res.emplace_back(e);
        for (auto e:R)  res.emplace_back(e);
    }
    return res;
}
vi solve(vi &v) {
    if (sz(v) <= 1) return v;
    int mid = sz(v)/2;
    vi L(v.begin(),v.begin() + mid),R(v.begin() + mid,v.end());
    L = solve(L);
    R = solve(R);
    return merge(L,R);
}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        int m;  cin >> m;
        vi v(m);
        for (int i = 0; i < m; i ++) cin >> v[i];
        vi ans = solve(v);
        if (is_sorted(all(ans))) {
            cout << cont << "\n";
        }
        else cout << "-1\n";
        cont = 0;
    }
    return 0;
}