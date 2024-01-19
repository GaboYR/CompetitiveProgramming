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
ll pot(ll k,ll e) {
    ll ans = 1;
    while (e --) {
        ans *= k;
    }
    return ans;
}
int main(){
    fast_io
    ll l,r,k;   cin >> l >> r >> k;
    bool is = false;
    for (ll i = 1; i <= r; i *= k) {
        if (i >= l && i <= r) {
            is = true;
            cout << i << " "; 
        }
        if (i > r / k) break;
    }
    if (!is)    cout << -1;
    cout << "\n";
    return 0;
}