#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define cin std::cin
#define cout std::cout
#define pb push_back
using ll = long long;
using ld = long double;
using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;
map<int,int> p,q;
ll cont = 0;
ll res = 0;
vi v,contL,contR;
const int maxn = 1e6 + 1;
ll solve(int l, int r){
    if (l == r) return 0;
    int mi = (l+r)/2;
    int ret = solve(l, mi) + solve(mi, r);
    
    vector<int>vl,vr;
    for(int i=l ; i < mi ; i++) vl.pb(contL[i]);
    for(int i=mi ; i <r ; i++) vr.pb(contR[i]);

    vi pre(maxn,0);
    sort(all(vr));

    int j = 0;
    int len = (int)vr.size();    
    for(int i = 1; i <maxn ; i++){
        pre[i] = pre[i-1];
        while(j < len and vr[j]<=i)
            pre[i]++;
    }
    for(auto e : vl) {
        ret += pre[e - 1];
    }
    return ret;
}
int main(){
    fast_io
    int n;  cin >> n;
    v.resize(n);
    contL.resize(n);
    contR.resize(n);
    for (int i = 0; i < n; i ++)    cin >> v[i];
    for (int i = 0; i < n; i ++) {
        contL[i] = ++ p[v[i]];
        contR[n - i - 1] = ++ q[v[n - i - 1]];
    }

    cout << solve(0, n) << endl;

    return 0;
}