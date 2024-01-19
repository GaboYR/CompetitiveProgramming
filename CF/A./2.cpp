#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
string s[1000];
int p[1000];
int res = -3200000;
int main () {
    int n;  cin >> n;
    map<string,int> mp,mp2;
    string ans;
    for (int i = 0; i < n; i ++) {
        cin >> s[i] >> p[i];
        mp[s[i]] += p[i];
    }
    for (auto e: mp) {
        res = max(e.second,res);
    }
    bool find = false;
    for (int i = 0; i < n && !find; i ++) {
        mp2[s[i]] += p[i];
        if (mp2[s[i]] >= res && mp[s[i]] == res){
            ans = s[i];
            find = true;
        }
    }
    cout << ans << '\n';
}