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
ll mod = 1e9 + 7;
ll n,m,k,r,c;
ll ax,ay,bx,by;
ll res;
ll fast_exp(ll k,ll e) {
    if (e == 0) return 1ll;
    ll u = fast_exp(k,e/2);
    u = (u * u) % mod;
    if (e % 2 == 1) u = (u * k) % mod;
    return u % mod;
}
int main(){
    fast_io
    cin >> n >> m >> k >> r >> c;
    cin >> ax >> ay >> bx >> by;
    if (ax == bx && ay == by)   res = n * m;
    else res = m * n - r * c;
    cout << fast_exp(k,res);
    return 0;
}