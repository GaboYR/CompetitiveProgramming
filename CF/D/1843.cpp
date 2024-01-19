#include<bits/stdc++.h>
using namespace std;
vector<int> graph[20005];
bool vis[20005];
int val[20005];
void bfs(int u) {
    int d = 0;
    val[u] = d;
    vis[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        d ++;
        for (int i = 0; i < size(graph[v]); i ++) {
            if (!vis[graph[v][i]]) {
                vis[graph[v][i]] = 1;
                cout << graph[v][i] << " " << d << '\n';
                q.push(graph[v][i]);
            }
        }
    }
}
int main () {
    int TC; cin >> TC;
    while (TC --) {
        int n;  cin >> n;
        memset(val,0,sizeof val);
        memset(graph,0,sizeof graph);
        memset(vis,0,sizeof vis);
        for (int i = 0; i < n - 1; i ++) {
            int u,v;    cin >> u >> v;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        int q;  cin >> q;
        //dfs(1);
        // for (int i = 1; i <= n; i ++) {
        //     cout << val[i] << "->";
        // }
        bfs(1);
        while (q --) {
            int x,y;    cin >> x >> y;
        }
        cout << '\n';
    }
    return 0;
}