#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
bool cmp(ii a,ii b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC; cin >> TC;
    while (TC --) {
        int n;  cin >> n;
        vector<ii> coord;
        while (n --) {
            int x,y;    cin >> x >> y;
            coord.emplace_back(ii(x,y));
        }
        sort(coord.begin(),coord.end(),cmp);
        for (auto e : coord) {
            cout << e.first << " " << e.second << "\n";
        }
        coord.clear();
    }
    return 0;
}