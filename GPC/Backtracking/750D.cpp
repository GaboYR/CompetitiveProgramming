#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500;
int t[30];
int board[MAXN][MAXN];
int n;
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
long long res = 0;
void print() {
    for (int i = 0; i < MAXN; i ++) {
        for (int j = 0; j < MAXN;j ++) {
            res += board[j][i];
        }
    }
}
void dfs(int x,int y,int c,int ang) {
    if (c == n) return;
    for (int i = 0; i < t[c]; i ++) {
        board[x + i * dx[ang] + (0)][y + i * dy[ang]] = 1;
    }
    int _x = x + (t[c] - 1) * dx[ang] + dx[(ang + 1) % 8];
    int _y = y + (t[c] - 1) * dy[ang] + dy[(ang + 1) % 8];
    int x_ = x + (t[c] - 1) * dx[ang] + dx[(ang + 7) % 8];
    int y_ = y + (t[c] - 1) * dy[ang] + dy[(ang + 7) % 8];
    int _ang = (ang + 1) % 8;
    int ang_ = (ang + 7) % 8;
    dfs(_x, _y, c + 1, _ang);
    dfs(x_, y_, c + 1, ang_);
}
int main () {
    cin >> n;
    memset(board,0,sizeof board);
    for (int i = 0; i < n; i ++)    cin >> t[i];
    dfs(MAXN/2,MAXN/2,0,6);
    print();
    cout << res << "\n";
    return 0;
}