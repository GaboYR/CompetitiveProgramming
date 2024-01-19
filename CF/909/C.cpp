#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 3;
int a[maxn];
int kadane(int l,int r) {
    int sum = 0;
    int res = a[l];
    for (int i = l; i <= r; i ++) {
        sum += a[i];
        res = max(res,sum);
        //if (sum < 0)    sum = 0;
    }
    return res;
}
int p(int i) {
    return abs(a[i]) % 2;
}
int main () {
    int tt; cin >> tt;
    while (tt --) {
        int n;  cin >> n;
        for (int i = 0; i < n; i ++)    cin >> a[i];
        int ind = 1;
        int l = 0;
        int mn = 0;
        while (n != 1 && ind <= n) {
            //cout << l << " " << ind << "\n";
            if (p(ind) != p(ind - 1)) {

            }
            else {
                mn = max(kadane(l,ind -1),mn);
                l = ind;
            }
            ind ++;
        }
        cout << max(mn,kadane(l,ind - 1)) << "\n";
        //cout << kadane(l,ind);
    }
    return 0;
}