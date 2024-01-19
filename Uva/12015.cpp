#include<bits/stdc++.h>
using namespace std;
int main() {
    int tt; cin >> tt;
    for (int i = 1; i <= tt; i ++) {
        cout << "Case #" << i << ":\n";
        int mx = 0;
        map<int,vector<string>> mp;
        for (int j = 0; j < 10; j ++) {
            
            string s;
            int v;
            cin >> s >> v;
            mx = max(v,mx);
            mp[v].emplace_back(s);
        }
        for (auto e:mp) {
            if (e.first == mx) {
                for (auto f : e.second) {
                    cout << f << "\n";
                }
            }
        }

    }
}