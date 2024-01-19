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
int n,m;
int r[3],c[3];
int board[10][10];
int times[3];
bool check(int i,int j){
    return board[i][j];
}
void back(int i,int j, int t) {
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};

}
int main(){
    fast_io
    while (cin >> n >> m, m&n) {
        for (int i = 0; i < 3; i ++) {
            cin >> r[i] >> c[i];
            times[i] = (i + 1) * m * n;
            times[i] /= 4;
        }
        //solve();
    }
    return 0;
}