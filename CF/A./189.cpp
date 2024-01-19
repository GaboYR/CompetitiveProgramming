#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
int main(){
    fast_io;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    for (int i = 0; i * a <= n;i ++){
        for (int j = 0; i * a + j * b <= n; j ++){
            int k = (n - i * a - j * b) / c;
            if(a * i + b * j+ c * k == n){
                ans = max(ans,i + j + k);
            }
        }
    }
    cout << ans;
    return 0;
}