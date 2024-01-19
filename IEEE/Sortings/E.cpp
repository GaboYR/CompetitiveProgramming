#include<bits/stdc++.h>
using namespace std;
const int mod = 1e6;
const int maxn = 5e6 + 5;
int cont[mod + 1];

long long n,a,b,v;
int solve(long long p) {
    return (a * p  + b) % mod;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b >> v;
    for (int i = 1; i <= n; i ++) {
        int x = solve(v) + 1;
        cont[x] ++;
        v = x;
    }
    for (int i = 1; i <= mod; i ++){
        while (cont[i] != 0) {
            cout << i << " ";
            cont[i] --;
        }
    }
}