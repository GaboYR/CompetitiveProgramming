#include<bits/stdc++.h>
using namespace std;
const int N = 8;
int board[N][N];
int r[8][10];
int c[8][10];
int b[2][2][10];
bool POSS = true;
void print_sudoku() {
    cout << "YES\n";
    for (int i = 0; i < N;i ++) {
        for (int j = 0; j < N; j ++) {
            cout << board[i][j] << " \n"[j + 1 == N];
        }
    }
}
void update_grid(int i,int j,int num,int delta) {
    r[i][num] += delta;
    c[j][num] += delta;
    b[i/4][j/4][num] += delta;
}
bool check(int i,int j,int num) {
    if (r[i][num])  return 0;
    if (c[j][num])  return 0;
    if (b[i/4][j/4][num] >= 2)  return 0;
    return 1;
}
void dfs(int i,int j) {
    if (i == N) return POSS = true,print_sudoku();
    if (j == N) return dfs(i + 1,0);
    if (board[i][j])    return dfs(i,j + 1);
    for (int num = 1; num <= 8; num ++) {
        if (!check(i,j,num))    continue;
        update_grid(i,j,num,1);
        board[i][j] = num;
        dfs(i,j + 1);
        board[i][j] = 0;
        update_grid(i,j,num,-1); 
    }
}
void setup(){
    memset(r,0,sizeof r);
    memset(c,0,sizeof c);
    memset(b,0,sizeof b);
}
void solve() {
    setup();
    POSS = true;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (board[i][j]) {
                if (check(i,j,board[i][j])){
                    update_grid(i,j,board[i][j],1);
                }
                else {
                    POSS = false;
                }
            }
        }
    }
    if (POSS) {
        POSS = false;
        dfs(0,0);
    }
    if (!POSS) {
        cout << "NO\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    int cs = 1;
    while (tt --) {
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++)    cin >> board[i][j];
        }
        cout << "Test case #" << cs ++ << ": ";
        solve();
    }
    return 0;
}