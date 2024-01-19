#include<bits/stdc++.h>
using ll = unsigned long long;
using namespace std;
ll mod = 1e9 + 7;
vector<pair<pair<ll,ll>,int>> grupos;
ll f(ll x,ll b) {
    ll ans = -1;
    ll res = 1;
    while (res <= x) {
        ans ++;
        res *= b;
    }
    return ans;
}
ll g(ll x) {
    return f(x,f(x,2));
}
ll fast_exp(ll k,ll e) {
    if (e == 0) return 1ll;
    ll u = fast_exp(k,e/2);
    u = (u * u);
    if (e % 2 == 1) u = (u * k);
    return u;
}
ll mul(ll x, ll y){
    x %= mod;
    y %= mod;
    return (x * y) % mod;
}
ll query(ll l,ll r) {
    int L = 0,H = 69;
    while (L < H) {
        int mid = L + (H - L)/2;
        if (grupos[mid].first.first > l) {
            H = mid;
        }
        else L = mid + 1;
    }
    if (grupos[L].first.first > l)  L --;
    int L2 = 0,H2 = 69;
    while (L2 < H2) {
        int mid = L2 + (H2 - L2)/2;
        if (grupos[mid].first.first > r) {
            H2 = mid;
        }
        else L2 = mid + 1;
    }
    if (grupos[L2].first.first > r)  L2 --;
    ll res = 0;
    if (L == L2) {
        res = (r - l + 1) * grupos[L].second % mod;
        res %= mod;
    }
    else {
    for (int i = L;i <=L2; i ++) {
            if (i == L) {
                res += mul(grupos[i].first.second - l + 1 , grupos[i].second);    
                res %= mod;
            }
            else if (i == L2) {
                res += mul(r - grupos[i].first.first + 1, grupos[i].second);
                res %= mod;
            }
            else {
                res += mul(grupos[i].first.second - grupos[i].first.first + 1, grupos[i].second);
                res %= mod;
            }
            if(grupos[i].first.second - grupos[i].first.first < 0)  cout << ":v";
        }
    }
    return res;
}
int main () {
    int q;  cin >> q;
    ll low = 4;
    ll high = 1e18;  
    while (low <= high) {
        ll fir = low;
        ll sec = low + low - 1;
        if (g(fir) == g(sec)) {
            grupos.emplace_back(make_pair(make_pair(fir,sec),g(fir)));
        }
        else {
            ll tmp = g(fir)+ 1;
            ll b = fast_exp(f(fir,2),tmp);
            grupos.emplace_back(make_pair(fir,b - 1),tmp - 1);
            grupos.emplace_back(make_pair(b,min(high,sec)),tmp);
        }
        low *= 2;
    }
    auto e = grupos.back();
    grupos.pop_back();
    e.first.second = high;
    grupos.emplace_back(e);
    while (q --) {
        ll l,r; cin >> l >> r;
        cout <<  query(l,r) << "\n";
    }
    return 0;
}