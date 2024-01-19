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
ll v[maxn], p[maxn];
ll n;
void solve() {
    for (int i = n - 1; i > 0; i --) {
        p[i] = i - 1;
    }
    ll x = n - 1;
    //int it = 20;
    while (x ){
        ll y = x;
        if (v[y] >= v[y - 1]) {
            p[y] = p[y - 1];
            y --;
        }
        else{
            if (y) {
                while (v[x] < v[y - 1] && v[y] < v[y - 1]){
                    y --;
                }
            } 
        }
        //cout << y << " " << v[y] << " "<< v[y - 1] << "\n";
        if (y == 1 && v[y] < v[y - 1]){
            y = 0;
        }
        //cout << y << "\n";
        //cout << x << " " << y << "\n";
        for (int i = x; i > y; i --) {
            //cout << i << " -> " << y; 
            p[i] = y;
        }
        x = y;
    }
}
int main(){
    fast_io
    ll h,a,c,q;  cin >> n >> h >> a >> c >> q;
    v[0] = h;
    for (int i = 0; i < n - 1; i ++) {
        v[i + 1] = (v[i] * 1ll * a + c + 0ll) % q;
    }
    solve();
    ll ans = 0;
    for (int i = 0; i < n; i ++) {
        //cout << v[i] << " " << p[i] << " " << i << "\n";
        ans += i - p[i];
        //cout << v[i] << " ";
        //cout << n - i - 1 << " " << p[n - i - 1] << " " << v[n - 1 - i] << "\n";
    }
    cout << ans << "\n";
    return 0;
}