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
const int maxn = 1e7 + 2;
int v[maxn], p[maxn];
ll n;
void solve() {
    for (int i = 0; i < n; i ++) {
        p[i] = i + 1;
    }
    p[n - 1] = n - 1;
    ll x = 0;
    while (x < n) {
        ll y = x;
        if (v[y] <= v[y + 1] && n != 1) {
            y ++;
        }
        else {
            if (y + 1 < n) {
                while (v[x] > v[y + 1] && v[y] > v[y + 1] && y < n - 1) {
                    if (y + 1 < n) y ++;
                }
            }
        } 
        for (int i = x;i < y; i ++) {
            p[i] = y;
        }
        if (y == n - 1) y = n;
        x = y;
    }
    for (int i = 0; i < n - 1;) {
        while (v[i] > v[p[i]] && p[i] < n - 1 ) {
            p[i] = p[p[i]];
            //v[i] = p[i]; 
        }
        i ++;
    }
}
int main(){
    fast_io
    ll h,a,c,q;  cin >> n >> h >> a >> c >> q;
    v[0] = h;
    // v[0] = 6;
    // v[1] = 5;
    // v[2] = 4;
    // v[3] = 3;
    // v[4] = 4;
    // v[5] = 3;
    for (int i = 0; i < n - 1; i ++) {
        //v[i + 1] = h - i - 1;
        //v[i + 1] = (v[i] * 1ll * a + c + 0ll) % q;
        ll r = (v[i] * 1ll * a + c + 0ll) % q;
        v[i + 1] = r;
    }
    v[n] = 1e9;
    //v[n - 1] = v[n - 2];
    solve();
    ll ans = 0;
    for (int i = 0; i < n; i ++) {
        //cout << v[i] << " " << i << " " << p[i] << "\n";
        ans += p[i] - i;
    }
    cout << ans << "\n";
    return 0;
}