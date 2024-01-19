//The Sultan Succesor
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 8;
int board[8][8],b[MAXN][MAXN];
vector<pair<int,int>> positions;
vector<pair<int,int>> queens;
vector<vector<pair<int,int>>> allSolution;
int ans = 0;
void findSum() {
    int res = 0;
    for (auto e:positions) {
        //cout << board[e.first][e.second] << "\n";
        res += board[e.first][e.second];
    }
    ans = max(ans,res);
    //    cout << res <<"\n";
    //return res;
}
void print(){
    for (auto e: positions) {
        b[e.first][e.second] = 1;//board[e.first][e.second];
    }
    for (int i = 0; i < MAXN; i ++) {
        for (int j = 0; j < MAXN; j ++) {
            cout << b[i][j] << " \n"[j==MAXN - 1];
        }
    }
    for (auto e: positions) {
        b[e.first][e.second] = 0;
    }
}
bool check(int r,int c) {
    for (auto e:queens) {
        if (r == e.first || 
            c == e.second || 
            abs(r - e.first) == abs(c - e.second)
            ){
            return false;
        }    
    }
    return true;
}
int cont = 0;
void back(int r) {
    if (r == MAXN) {
        cont ++;
        positions = queens;
        findSum();
        //cout << findSum() << "\n";
        //print();
        allSolution.emplace_back(positions);
        positions.clear();
        //cout << allSolution.size() << "\n";
    }
    for (int c = 0; c < MAXN; c ++) {
        if (check(r,c)){
            queens.emplace_back(make_pair(r,c));
            back(r + 1);
            queens.pop_back();
        }
    }
}
void show() {
    int tmp = ans;
    int cont = 0;
    while (ans){ 
        cont ++;
        ans/=10;
    }
    for (int i = 0; i < 5 - cont; i ++) cout << " ";
    cout << tmp << "\n";
}
int main() {
    
    int k;  cin >> k;
    while (k --) {
        for (int i = 0; i < 8;i ++){
            for (int j = 0; j < 8;j ++) cin >> board[i][j];
        }
        back(0);
        show();
    }
    return 0;
}