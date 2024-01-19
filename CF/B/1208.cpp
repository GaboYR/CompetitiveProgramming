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
const int maxn = 2e5;
int a[maxn];
int main(){
    fast_io
    int n;  cin >> n;
    map<int,int> mp;
    int cont = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    int i = 0,j = n - 1;
    while (1) {
        if (mp[a[i]] > 1) {
            mp[a[i]] --;
            i ++;
        }
        else break;
    }
    while (1) {
        if (mp[a[j]] > 1) {
            mp[a[j]] --;
            j --;
        }
        else break;
    }
    cout << n - (j - i + 1) << "\n";
    //cout << i << " " << j << "\n";
    return 0;
}