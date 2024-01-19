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
const int maxn = 1e8 + 1;
int arr[1300],dp[1300];
map<ll,int> mp;
int sumaSq(ll n) {
    int ans = 0;
    while (n) {
        ans += (n % 10) * (n % 10);
        n /= 10;
    }
    return ans;
}
void init() {
    for (int i = 1; i <= 1296; i ++) {
        arr[i] = sumaSq(i);
    }
}
void xd(ll n) {
    for (ll i = 0; i < n/1e9; i ++) {
        auto x = n % int(1e7);
        auto y = sumaSq(i) + sumaSq(x); 
    }
}

int query(ll a,ll b) {
    return sumaSq(b) - sumaSq(a - 1);
}
int main(){
    fast_io
    init();
    for (int i = 1; i <= 1296; i ++) {
        while (arr[i] != 1 && arr[i] != 4) {
            //cout << arr[i] << " "<< arr[arr[i]] << " " << "\n";
            arr[i] = arr[arr[i]];
        }
        //if (arr[i] == 4)    arr[i] = 0;
        dp[i] = dp[i - 1] + (arr[i] == 4?0:1);
        cout << i << " " << arr[i] << " " << dp[i] << "\n";
    }
    ll A,B; cin >> A >> B;
    if (A > 1000) {
        int preA = A / 1000;
        int modA = A % 1000;
        mp[A] += dp[A];
        if (preA > 1000) {
            
        }
    }
    //cout << query(b,a - 1);
    return 0;
}