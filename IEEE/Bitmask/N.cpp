#include<bits/stdc++.h>
using namespace std;
long long r,n,m;
long long  fast_exp(long long n,long long k) {
    if (k == 0) return 1ll;
    long long u = fast_exp(n,k/2);
    u = (u * u) % m;
    if (k % 2 == 1) u = (u * k) % m;
    return u % m;
}
long long f(long long n,long long k) {
    //1 + n + n² + ... + n^k 
    //1 + n + ... n^k/2 + n^(k/2 + 1)(1 + n + .., + n^k)
    if (k == 0) return 1;
    if (k == 1) return n + 1;
    return f(n,k/2) % m + fast_exp(n,k/2 + 1) * f(n,k - (k + 1)/2 + k%2 - 1) % m;
}
int main () {
    int tt;    cin >> tt;
    while (tt --) {
        cin >> r >> n >> m;
        m = 1e9 + 7;
        cout << f(r,n*n - 1) << "\n";
    }
    return 0;

}