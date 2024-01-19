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
ll f(ll t1,ll x1,ll t2,ll x2,ll t0){
    return t1 * x1 + t2 * x2 - t0 * (x1 + x2);
}
int main(){
    fast_io
    ll t1,t2,x1,x2,t0; cin >> t1 >> t2 >> x1 >> x2 >> t0;
    ll dif = 1e9;
    ll res1 = -1,res2 = -1;
    for (ll y1 = 0; y1 <= x1; y1 ++) {
        ll num = (t0 - t1) * y1;
        ll den = (t2 - t0);
        if (den != 0) {
            ll y2 = (num + den - 1)/den;
            if (dif >= f(t1,y1,t2,y2,t0) && (y2 != 0 || y1 != 0) && y2 <= x2) {
                dif = f(t1,y1,t2,y2,t0);
                res1 = y1,res2 = y2;
            }
            else {
                if (res1 == -1 && res2 == -1)
                res1 = 0,res2 = x2;
            }
        }
        else {
            res1 = 0,res2 = x2;
        }
        
    }
    ll g = __gcd(res1,res2);
    res1/=g;
    res2/=g;
    ll p1 = 1e7,p2 = 1e7;
    if (res1 != 0)  p1 = x1/res1;
    if (res2 != 0)  p2 = x2/res2;
    p1 = min(p1,p2);
    res1 *= p1;
    res2 *= p1; 
    if (res1 == 0 && res2 == 0) {
        res2 = x2;
    }
    if (t1 == t0 && t2 == t0)   res1 = x1,res2 = x2;
    cout << res1 << " " << res2 << "\n";
    return 0;
}