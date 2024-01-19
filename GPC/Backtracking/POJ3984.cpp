#include<iostream>
using namespace std;
const int n = 5;
const int maxd = 30;
int maze[n][n];
int ix = 0,iy = 0,fx = n - 1,fy = n - 1;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool vis[n][n];
int dist[n][n];
bool check(int r,int c) {
    if (r < 0 || r >= n || c < 0 || c >= n) return false;
    return true;
}
void dfs(int r,int c,int cnt) {
    dist[r][c] = min(dist[r][c],cnt);
    //cout << dist[r][c] << "\n";
    if (r == fx && c == fy) {
        //cout << "End\n";
        return;
    }
    
    vis[r][c] = 1;
    for (int i = 0; i < 4; i ++) {
        int r2 = r + dx[i];
        int c2 = c + dy[i];
        if (check(r2,c2)) {
            if (maze[r2][c2] == 0 && !vis[r2][c2]) dfs(r2,c2,cnt + 1);
            //else dist[r2][c2] = maxd;
        }
    }
    vis[r][c] = 0;
}
int main () {
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> maze[i][j];
            dist[i][j] = maxd;
        }
    }
    dfs(ix,iy,1);
    int d = dist[4][4];
    int rr[25],cc[25];
    rr[0] = cc[0] = 0;
    int r = 4,c = 4;
     while (r !=  0 || c != 0){
        //cout << "(" << r << ", "<< c << ")\n";
        d --;
        rr[d] = r,cc[d] = c;
        for (int i = 0; i < 4; i ++) {
            int r2 = r + dx[i];
            int c2 = c + dy[i];
            if (check(r2,c2)) {
                if (dist[r2][c2] == d){
                    r = r2,c = c2;
                }
            }
        }
    }
    //cout << "(0, 0)\n";
    for (int i = 0; i < dist[4][4]; i ++) {
        cout << "(" << rr[i] << ", " << cc[i] << ")\n";
    }
    return 0;
}