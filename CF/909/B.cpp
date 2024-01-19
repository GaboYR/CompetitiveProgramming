#include<bits/stdc++.h>
using namespace std;
const int maxn = 150000;
using ll = long long;
ll a[maxn],pref[maxn];
vector<int> cd(int k) {
    vector<int> res;
    for (int i = 1; i * i <= k; i ++) {
        if (k % i == 0) {
            res.emplace_back(i);
            if (i != k/i){
                res.emplace_back(k/i);
            }
        }
    }
    sort(res.begin(),res.end());
    return res;
}
int main () {
    int tt; cin >> tt;
    while (tt --) {
        int n;  cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }
        vector<int> divn = cd(n);

        ll glob = 0;
        for (auto e:divn) {
            ll mn = 1e18;
            ll mx = 0;
            for (int i = 0; i * e < n && e != n; i ++) {
                mn = min(pref[e * i + e] - pref[e * i],mn);
                mx = max(mx,pref[e * i + e] - pref[e * i]);
            }
            glob = max(glob,mx - mn);
            //cout << mx << " " << mn << "\n";
        }
        cout << glob << "\n";
    }
    return 0;
}