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
const int maxn = 2e5 +1;
int a[maxn];
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        int n;  cin >> n;
        a[0] = 0;
        map<int,int> pos;
        pos[0] = 0;
        for (int i = 1; i <= 2 * n; i ++) {
            int d;  cin >> d;
            a[i] += a[i - 1] + (d == 1?1:-1);
            if (i <= n) {
                pos[a[i]] = i;
            }
        }
        int ans = 2 * n;
        for (int i = n; i <= 2 * n; i ++) {
            if (pos.find(a[i] - a[2 * n]) != pos.end()){
                ans = min(ans,abs(i - pos[a[i] - a[2 * n]]));
            }
        }
        cout << ans << "\n";
        for (int i = 0;i <= 2 * n; i ++)    a[i] = 0;
        pos.clear();
    }
    return 0;
}