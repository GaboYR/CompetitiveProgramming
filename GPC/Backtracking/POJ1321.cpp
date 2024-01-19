#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k;
char board[10][10];
int ans = 0;
vector< pair < int, int > > pos;
bool check(int r,int c) {
    for (int i = 0;i < pos.size(); i ++){
        if (r == pos[i].first || c == pos[i].second)    return false;
    }
    return true;
}
void back(int c,int cnt) {
    if (cnt == k) {
        ans ++;
        return;
    }
    if (c == n) return;
    back(c + 1,cnt);
    for (int i = 0; i < n; i ++) {
        if (board[i][c] == '#' && check(i,c)) {
            pos.push_back(make_pair(i,c));
            back(c + 1,cnt + 1);
            pos.pop_back();
        }
    }
}
int main() {
    while (cin >> n >> k){
        if (n == -1 && k == -1)   break;
        int cont = 0;
        for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) cin >> board[i][j];
        back(0,0);
        cout << ans << "\n";
        ans = 0;
        pos.clear();
    }
    return 0;
}