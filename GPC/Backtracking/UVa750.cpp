#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> q,sol;
vector<vector<pair<int,int>>> solutions,filter_solutions;
vector<pair<int,int>> dataset;
bool check(int r,int c) {
    for (auto e: q) {
        if (e.first == r || e.second == c || abs(r - e.first) == abs(c - e.second)) return false;
    }
    return true;
}
void back(int c) {
    if (c == 8) {
        sol = q;
        solutions.emplace_back(sol);
    }
    else {
        for (int i = 0; i < 8; i ++) {
            if (check(i,c)) {
                q.emplace_back(make_pair(i,c));
                back(c + 1);
                q.pop_back();
            }
            
        }
    }
}
void filter(int a,int b) {
    int cnt = 1;
    for (auto s:solutions) {
        for (auto pos:s) {
            if (pos.first == a && pos.second == b){
                filter_solutions.emplace_back(s);
            }
        }
    }
    cout << "SOLN       COLUMN\n";
    
    cout << " #      1 2 3 4 5 6 7 8\n\n";
    for (auto fs:filter_solutions){
        cout << (cnt < 10?" ":"") << cnt ++ << "      ";
        for (int i = 0; i < 8;i ++) {
            cout << fs[i].first + 1 << " \n"[i == 7];
        }
    }
    filter_solutions.clear();
}
int main() {
    back(0);
    int tt; cin >> tt;
    while (tt --) {
        int a,b;    cin >> a >> b;
        a --; b --;
        filter(a,b);
        if (tt) cout << "\n";
    }
}