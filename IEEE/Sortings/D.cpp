#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[3 * maxn],b[3][maxn];
int main () {
    int n;  cin >> n;
    for (int i = 0; i < 3 * n; i ++)  cin >> a[i];
    
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)    cin >> b[i][j];
    
    
    return 0;
}