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
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        int n;  cin >> n;
        map<int,int> mp;
        for (int i = 0; i < n; i ++) {
            int d;  cin >> d;
            mp[d] ++;
        }
        int ans = 0;
        int curr = 0;
        for (auto e: mp) {
            e.second += curr;
            if (e.first <= e.second){
                ans += e.second / e.first;  
                curr = e.second % e.first;
            }
            else {
                curr = e.second;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}