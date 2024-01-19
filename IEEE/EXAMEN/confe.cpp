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
    map<string,int> mp;
    int cont = 0;
    while (tt --) {
        string s1,r,s2; cin >> s1 >> r >> s2;
        if (r == "??") {
            int v = mp[s1];
            int w = mp[s2];
            mp[s1] = mp[s2] = max(v,w);
        }
        else {
            mp[s1] = cont;
            mp[s2] = mp[s1] + 1;
            
        }
    }
    for (auto e: mp) {
        if (e.second == 0)cout << e.first << "\n";
    }
}