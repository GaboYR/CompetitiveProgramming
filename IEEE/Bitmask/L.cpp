#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
int a[maxn];
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;    cin >> n >> q;
    for (int i = 0; i < n; i ++)    cin >> a[i];
    while (q --) {
        string s;   cin >> s;
        vector<int> on;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '1')    on.emplace_back(a[i]);    
        }
        if (on.empty()) cout << 0;
        if (on.size() == 1) cout << on.back();
        else {
            vector<int> dp(on.size() - 1);
            dp[0] = on[0];
            for (int i = 1; i < dp.size(); i ++) {
                dp[i] = dp[i - 1]^on[i];
            }
        }
        cout << '\n';
    }
    return 0;
}