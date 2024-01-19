#include<iostream>
#include<cstring>
using namespace std;
int n,m;
char w[8] = "IEHOVA#";
char t[10][10];
int srcx,srcy,endx,endy;
int dx[] = {0,-1,0};
int dy[] = {-1,0,1};
int res[8];
bool check(int r,int c) {
    return (r >= 0 && r <= n && c >= 0 && c <= m);
}
void back(int x,int y,int c) {
    if (x == endx && endy == y && c == 7)   return;
    for (int i = 0; i < 3; i ++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx,ny) && t[nx][ny] == w[c]) {
            if (i == 0) cout << "left";
            else if (i == 1) cout << "forth";
            else if (i == 2) cout << "right";
            if (c < 6)  cout << " ";
            back(nx,ny,c + 1);
        }
    }
}
int main() {
    int TC; cin >> TC;
    while (TC --) {
        cin >> n >> m;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++){
                cin >> t[i][j];
                if (t[i][j] == '@') {
                    srcx = i;
                    srcy = j;
                }
                if (t[i][j] == '#') {
                    endx = i;
                    endy = j;
                }
            }
        }
        back(srcx,srcy,0);
        cout << '\n';
        memset(t,0,sizeof t);
    }
    return 0;
}