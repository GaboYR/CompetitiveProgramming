#include<bits/stdc++.h>
using namespace std;
const int maxn = 31;
int a[maxn];
int main () {
    a[2] = 2;
    for (int i = 2; i < 31; i ++) {
        a[i * 2] = 2 * a[i * 2 - 2];
    }
    int n;  cin >> n;
    cout << a[n] << '\n';
    return 0;
}   