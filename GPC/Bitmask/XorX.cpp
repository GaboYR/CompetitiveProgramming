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
const int maxn = 2e5 + 1;
int a[maxn],pref[maxn];
int main(){
    int tt; cin >> tt;
    while (tt --) {
        int n;  cin >> n;
        int x;  cin >> x;
        for (int i = 0; i < n; i ++)    cin >> a[i];
        pref[0] = a[0];
        for (int i = 1; i < n; i ++) {
            pref[i] = pref[i - 1] ^ a[i];
        }
        for (int i = 0; i < n; i ++) {
            cout << pref[i] << " " << (pref[i]^x) << "\n";
        }
    }
    return 0;
}