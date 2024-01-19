#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
long long sum(int n) {
    return 1ll * n * (n + 1) / 2 % 10000;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,U,Q;  cin >> N >> U >> Q;
    vector<ii> ranges;
    while (U --) {
        int a,b;    cin >> a >> b;
        ranges.emplace_back(ii(a,b));
    }
    //for (auto e : ranges)   cout << e.first << " " << e.second << "\n";
    while (Q --) {
        int l,r;    cin >> l >> r;
        long long res = 0;
        for (auto e : ranges) {
            if (l > e.second || r < e.first)    continue;
            else {
                int start = max(e.first,l) - e.first + 1;
                int last = min(r,e.second) - max(e.first,l) + start;
                //cout << start << " " << last << "\n";
                res += (sum(last) - sum(start - 1) + 10000) % 10000;
            }
        }
        cout << res % 10000 << "\n";
    }
}