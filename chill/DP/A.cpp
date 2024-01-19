#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 3;
long long dp[maxn];
long long hexabonacci(int n) {
    if (n < 6) return dp[n];
    for (int i = 6;i <= n; i ++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6];
        dp[i] %= 10000007;
    }
    return dp[n];
}
int main () {
    int TC; cin >> TC;
    for (int cs = 1; cs <= TC; cs ++) {
        for (int i = 0; i < 6; i ++)    cin >> dp[i];
        int ind;    cin >> ind;

        cout << "Case " << cs << ": " << hexabonacci(ind) % 10000007 << "\n";
        memset(dp,0,sizeof dp);
    }
    return 0;
}