#include<bits/stdc++.h>
#define sz(x) int(x.size())
using namespace std;
void print(vector<vector<int>> &b){
    int n = sz(b);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++){
            cout << b[i][j] << " \n"[j + 1 == n];
        }
    }
}
int solve(vector<vector<int>> &a) {
    //print(a);
    vector<int> v(sz(a),0);
    vector<vector<int>> dp(sz(a),v);
    //cout << dp.size() << ' ' << dp[0].size() << '\n';
    int s = sz(a);
    dp[0][0] = a[0][0];
    for (int i = 0; i < s; i ++) {
        for (int j = 0; j < s; j ++) {
            if (i > 0 && j == 0) dp[i][j] = a[i][j] + dp[i - 1][j];
            if (j > 0 && i == 0) dp[i][j] = a[i][j] + dp[i][j - 1]; 
        }
    }
    for (int i = 0; i < s; i ++) {
        for (int j = 0; j < s; j ++) {
            if (i && j) {
                dp[i][j] = a[i][j] + max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    return dp[s - 1][s - 1];
}

int main () {
    cin.tie(nullptr)->sync_with_stdio(false);
    int TC; cin >> TC;
    for (int i = 1; i <= TC; i ++) {
        int n;  cin >> n;
        vector<int> v(n,0);
        vector<vector<int>> a(n,v);
        //print(a);
        int x = 0, y = 0,cx = 0,tp = n - 1; 
        while (x < n - 1 || y < n - 1) {
            cin >> a[x][y];
            if (x == max(0,cx - tp)) {
                cx ++;
                if (cx <= tp) {
                    x = cx;
                    y = 0;
                }
                else {
                    x = tp;
                    y = cx - tp;
                }
            }
            else {
                if (x) {
                    x --;
                    y ++;
                }
            }
        }
        cin >> a[x][y];
        cout << "Case " << i << ": " << solve(a) << '\n';
        a.clear();
        //print(dp);
    }
    return 0;
}