#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> sol,queen;
vector<vector<pair<int,int>>> S;
int n = 8;
bool check (int r,int c) {
    for (auto e : queen) {
        if (r == e.first || c ==e.second || abs(r - e.first) == abs(c - e.second)) return false;
    }
    return true;
}
void back(int c) {
    if (c == n) {
        S.emplace_back(queen);
    }
    for (int i = 0; i < n; i++) {
        if (check(i,c)) {
            queen.emplace_back(make_pair(i,c));
            back(c + 1);
            queen.pop_back();
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    back(0);
    int tc = 1;
    int pos[8];
    while (cin >> pos[0]) {
        for (int i = 1; i < 8; i ++)    cin >> pos[i];
        cout << "Case " << tc ++ << ": ";
        int mn = 8;
        for (auto solu:S) {
            int dif = 0;
            for (int i = 0; i < n; i ++) {
                dif += (solu[i].first != pos[i] - 1);
            }
            mn = min(mn,dif);
        }
        cout << mn << "\n";
    }
    return 0;
}