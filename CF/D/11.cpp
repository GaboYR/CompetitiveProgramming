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
vector<int> g[20];
vector<bool> vis(20,0);
ll res = 0;
void dfs(int u,int v,int count) {
    //if (g[u].size() != 0)   cout << u << " ";
    if (u == v && count <= 2)   return;
    if (count > 2) {
        for (auto e:g[u]) {
            if (e == v) {
                cout << "\n";
                res++;
                break;
            }
        }
    }
    vis[u] = 1;
    if (g[u].size() != 0) {
        for (auto e: g[u]) {
            if (!vis[e]) {
                //vis[e] = 1;
                dfs(e,v,count + 1);
                //vis[e] = 0;
            }
        }
    }
}
void add(int u,int v) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
}
int main(){
    fast_io
    int n,m;    cin >> n >> m;
    for (int i = 0; i < m; i ++){
        int u,v;    cin >> u >> v;
        add(u,v);
    }
    //dfs(1,2,0);
    for (int i = 0; i < 20; i ++) {
        for (int j = 0; j < sz(g[i]); j ++) {
            for (int k = 0; k < sz(g[i]); k ++) {
                dfs(g[i][j],g[i][k],0);
            }
        }
    }
    cout << res;
    return 0;
}