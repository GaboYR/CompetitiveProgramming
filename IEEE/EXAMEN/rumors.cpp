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
int main(){
    fast_io
    int tt; cin >> tt;  
    map<string,int> mp,mpdude;
    vector<pair<string,string>> v;
    map<string,string> mpd;
    while (tt --) {
        string s1,rum,s2;   cin >> s1 >> rum >> s2;
        if (rum == "??") {
            v.emplace_back(make_pair(s1,s2));
        }
        else {
            mp[s1] = 100;
            mp[s2] = -100;
        }
    }
    for (auto [a,b]:v) {
        if (mp[a] == 0 && mp[b] == 100)     mp[a] = 100;
        else if (mp[a] == 0 && mp[b] == -100)    mp[a] = -100;
        else if (mp[a] == 100 && mp[b] == 0)     mp[b] = 100;
        else if (mp[a] == 0 && mp[b] == 0)  mp[b] == 100;
    }
    for (auto e: mp){
        if (e.second == 100)  cout << e.first << "\n";
    }
    return 0;
}