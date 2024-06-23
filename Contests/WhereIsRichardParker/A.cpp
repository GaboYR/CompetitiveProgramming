#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n,l,r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < v.size();i ++)    v[i] = i + 1;
    l --, r --;
    reverse(v.begin() + l, v.begin() + r + 1);
    for (int i : v) cout << i << ' ';
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}