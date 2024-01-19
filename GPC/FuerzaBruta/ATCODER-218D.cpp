#include<bits/stdc++.h>
using namespace std;
int intersection(set<int> &a,set<int> &b) {
    int res = 0;
    for (auto e:a) {
        res += b.count(e);
    }
    return res;
}
int main () {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;  cin >> n;
    map<int,set<int>> mp;
    long long res = 0;
    for (int i = 0; i < n; i ++) {
        int a,b;    cin >> a >> b; 
        mp[a].insert(b);
    }
    for (auto it = mp.begin(); it != mp.end(); it ++) {
        for (auto ti = next(it); ti != mp.end(); ti ++) {
            auto a = it->second;
            auto b = ti->second;
            int r = intersection(a,b);
            res += 1ll * (r - 1) * (r) / 2;
        }
    }
    cout << res << '\n';
    return 0;
}