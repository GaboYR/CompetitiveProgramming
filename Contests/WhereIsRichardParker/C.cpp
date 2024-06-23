#include<bits/stdc++.h>
using namespace std;
int comb(int n,int k) {
    long long num = 1;
    long long den = 1;
    for (int i = 0; i < k; i ++) {
        num *= (n - i);
        den *= (i + 1);
    }
    return num / den;
}
void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    int c;
    vector<char> r(m);
    vector<int> bitmask(m);
    for (int i = 0; i < m; i ++) {
        cin >> c;
        while (c --) {
            int x;
            cin >> x;
            bitmask[i] |= 1 << x - 1;
        }
        cin >> r[i];
    }
    int res = 0;
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < m ; j ++) {
            if (r[i] == 'o' && r[j] == 'x') {
                //cout << bitmask[i] << " " << bitmask[j] << '\n';
                int dif_bit = bitmask[i] & ~bitmask[j];
                int and_bit = bitmask[i] & bitmask[j];
                //cout << dif_bit << " " << and_bit << '\n';
                int pd = __builtin_popcount(dif_bit);
                res += comb(__builtin_popcount(and_bit),k - pd);
            }
        }
    }
    cout << res;
    cout << '\n';
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}