#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 3;
int a[maxn],freq[maxn];
int main(){
    int n,x;    cin >> n >> x;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        freq[a[i]] ++;
    }
    long long res = 0;
    for (int i = 0;i < n; i ++) {
        res += freq[a[i]^x];
        if (x == 0) res --;
    }
    cout << res / 2 << "\n";
}