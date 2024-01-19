#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> q;
int n;
int totalSol = 0;
bool check(int &r,int &c) {
    for (auto e: q) {
        if (r == e.first || c == e.second || abs(r - e.first) == abs(c - e.second)) return false;
    }
    return true;
}
void back(int c) {
    if (c == n) {
        totalSol ++;
        return;
    }
    for (int i = 0; i < n; i ++) {
        if (check(i,c)) {
            q.emplace_back(make_pair(i,c));
            back(c + 1);
            q.pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    scanf("%d",&n);
    back(0);
    printf("%d",totalSol);
    return 0;
}