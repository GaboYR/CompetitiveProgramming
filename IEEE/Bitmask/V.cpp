#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 2;
int a[maxn];
map<int,int> mp;
int main () {
    int n;  cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    
    sort(a,a + n);
    int l = a[n - 1];
    vector<int> sol;
    vector<int> mx;
    vector<vector<int>> all;
    for (int i = 0; i < n; i ++) {
        int res = 0;
        int j = 0;
        sol.emplace_back(a[i]);
        while (a[i] + (1<<j) <= l) {
            if (mp[a[i] + (1<<j)] != 0) {
                res ++;
                sol.emplace_back(a[i] + (1<<j));
            }
            j ++;
        }
        if (sol.size() > 1) {
            if (mx.empty()) mx = sol;
            else {
                if (sol.size() > mx.size()) mx = sol;
            }
        }
        sol.clear();
    }
    if (mx.empty()) {
        cout << "1\n" << a[0] << "\n";
    }
    else {
        if (mx.size() > 3) {
            cout << mx.size() - 1 << "\n";
            int i = 0,j = 1;
            int d = a[j] - a[i];
            for (int i = 0; i < mx.size() - 1; i ++) {
                cout << mx[i] << " ";
            }
            cout << '\n';
        }
        else {
            cout << mx.size() << "\n";
            for (int i = 0; i < mx.size(); i ++) {
                cout << mx[i] << " ";
            }
            cout << '\n';
        }
    }
    
    return 0;
}