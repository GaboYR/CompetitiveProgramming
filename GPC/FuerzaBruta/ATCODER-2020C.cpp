#include <bits/stdc++.h>
using namespace std;
int ans[10101];
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;  cin >> n;

    for (int x = 1; x <= 100; x++) {
        for (int y = 1; y <= 100; y++) {
            for (int z = 1; z <= 100; z++) {
                int res = x * x + y * y + z * z + x * y + y * z + z * x;
                if (res <= n)
                    ans[res]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}