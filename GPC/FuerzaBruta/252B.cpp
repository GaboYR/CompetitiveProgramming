#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int n;
bool sorted() {
    bool p = is_sorted(a,a + n);
    for (int i = 0; i < n; i ++)    a[i] = -a[i];
    bool q = is_sorted(a,a + n);
    return p || q;
}
int main () {
    cin >> n;
    for (int i = 0; i < n; i ++)    cin >> a[i];
    bool is = (n >= 3);
    int i = 0,j = 1,k = 2;
    while (k < n && is) {
        cout << i << " " << j << ' '  << k << '\n';
        if (a[i] < a[j]) {
            if (a[j] < a[k])    k ++;
            else j ++;
        }
        else if (a[i] > a[j]) {
            if (a[k] > a[j])    k ++;
            else j ++;
        }
        
        //else break;
    }
}