#include<bits/stdc++.h>
using namespace std;
const int N = 8;
int r[10][10];
int c[10][10];
int b[2][2][10];
int board[10][10];
bool pos = true;
void init() {
    memset(r,0,sizeof r);
    memset(c,0,sizeof c);
    memset(b,0,sizeof b);
}
void print_sudoku() {
    cout << "YES\n";
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cout << board[i][j] << " \n"[j + 1 == N];
        }
    }
    return;
    
}
void update_board(int i,int j,int num,int delta) {
    r[i][num] += delta;
    c[j][num] += delta;
    b[i/4][j/4][num] += delta;
}
bool check (int i,int j,int num) {
    if (r[i][num])  return false;
    if (c[j][num])  return false;
    if (b[i/4][j/4][num] >= 2)  return false;
    return true;
}
void dfs(int i,int j) {
    if (i == N) return pos = true,print_sudoku();
    if (j == N) return dfs(i + 1,0);
    if (board[i][j])    return dfs(i,j + 1);
    for (int num = 1; num <= 8; num ++) {
        if (check(i,j,num)) {
            update_board(i,j,num,1);
            board[i][j] = num;
            dfs(i,j + 1);
            board[i][j] = 0;
            update_board(i,j,num,-1);
        }   
        // if (!check(i,j,num))    continue;
        // update_board(i,j,num,1);
        // board[i][j] = num;
        // dfs(i,j + 1);
        // board[i][j] = 0;
        // update_board(i,j,num,-1);
    }
}
void solve() {
    init();
    pos = true;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (board[i][j]) {
                if (check(i,j,board[i][j])){
                    update_board(i,j,board[i][j],1);
                }
                else {
                    pos= false;
                }
            }
        }
    }
    if (pos) {
        pos = false;
        dfs(0,0);
    }
    if (!pos) {
        cout << "NO\n";
    }
}
int main () {
    int TC; cin >> TC;
    for (int t = 1; t <= TC; t ++) {
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {
                cin >> board[i][j];
            }
        }
        cout << "Test case #" << t << ": ";
        solve();
    }
    return 0;
}