#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 40;
const int inf = 270000;
char a[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
int d[maxn][maxn][maxn];
int L,R,C;
int sl,sr,sc,el,er,ec;
int mx = inf;
int dx[] = {-1,1,0,0,0,0};
int dy[] = {0,0,-1,1,0,0};
int dz[] = {0,0,0,0,-1,1};
int abs(int n) {
    return n > 0? n: -n;
}
void print() {
    for (int i = 0; i < L; i ++) {
        for (int j = 0; j < R; j ++) {
            for (int k = 0; k < C; k ++) {
                cout << d[i][j][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
bool check(int l,int r,int c) {
    if (l < 0 || l >= L || r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}
void back(int l,int r,int c,int cnt) {
    d[l][r][c] = cnt;
    if (l == el && r == er && c == ec) return;
    //Mijail gozu
    if (abs(el - l) + abs(er - r) + abs(ec - c) + d[l][r][c] >= d[el][er][ec])  return;
    for (int i = 0; i < 6; i ++) {
        int l2 = l + dz[i];
        int r2 = r + dx[i];
        int c2 = c + dy[i];
        if (check(l2,r2,c2) && !vis[l2][r2][c2] && a[l2][r2][c2] != '#' && d[l][r][c] + 1 < d[l2][r2][c2]) {
            back(l2,r2,c2,cnt + 1);
        }
    }
    vis[l][r][c] = 0; 
}   
int main () {
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> L >> R >> C) {
        if (L + C + R == 0) break;
        for (int i = 0; i < L; i ++) {
            for (int j = 0; j < R; j ++) {
                for (int k = 0; k < C; k ++) {
                    cin >> a[i][j][k];
                    if (a[i][j][k] == 'S'){
                        sl = i, sr = j, sc = k;
                    }
                    if (a[i][j][k] == 'E') {
                        el = i, er = j, ec = k;
                    }
                }
            }
        }
        for (int i = 0; i < L; i ++) 
            for (int j = 0; j < R; j ++) 
                for (int k = 0; k < C; k ++) 
                    d[i][j][k] = inf;
        
        back(sl,sr,sc,0);
        //print();
        //cout << d[sl][sr][sc] << " " << d[el][er][ec] << "\n";
        if (d[el][er][ec] < inf)  cout << "Escaped in " << d[el][er][ec] << " minute(s).\n";
        else            cout << "Trapped!\n";

        memset(vis,0,sizeof vis);
        memset(a,0,sizeof a);
    }
    return 0;
}