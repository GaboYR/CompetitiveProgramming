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
ll c[7];
ll x,y;
void solve() {
    // horizontal y vertical
    ll ans1 = abs(x) * c[x >= 0 ? 6:3] + abs(y) * c[y>= 0 ? 2:5];
    //diag y vert
    ll ans2 = abs(y) * c[y >= 0 ? 1:4] + abs(y - x) * c[x - y >= 0 ? 6:3];
    //diag y 
    ll ans3 = abs(x) * c[x >= 0 ? 1:4] + abs(y - x) * c[y - x >= 0 ? 2:5];
    //cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    cout << min(ans1,min(ans2,ans3)) << "\n";
    

}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        cin >> x >> y;
        for (int i = 1; i < 7; i ++)    cin >> c[i];
        solve();
    }
    return 0;
}