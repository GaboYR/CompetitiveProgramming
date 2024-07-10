#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a, solution;
void print() {
    cout << '{';
    for (int i = 0; i < k; i ++) {
        cout << solution[i] << (i < k - 1?",":"");
    }
    cout << '}' << '\n';
}
void bt(int pos, int it) {   
    if (it > k) return;
    if (pos == n) {
        if (it == k) print();
        return;
    }
    solution.push_back(a[pos]);
    bt(pos + 1,it + 1);
    solution.pop_back();
    bt(pos + 1,it);
}
void solve () {
    // n : tam del arreglo
    // k : tam del cjto
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i ++)    cin >> a[i];
    sort(a.begin(),a.end());
    bt(0,0);
    cout << "---\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}