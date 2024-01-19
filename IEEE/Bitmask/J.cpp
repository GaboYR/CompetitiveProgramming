#include<bits/stdc++.h>
using namespace std;
long long solve(long long a,long long b,bool op) {
    if (op == 0) {
        while (a < b)   a|=(a + 1);
        return a;
    }
    else {
        while (b > a)   b&=(b - 1);
        return b;
    }
}
int main () {
    int TC; cin >> TC;
    long long a,b;
    for (int i = 1; i <= TC; i ++) {
        cin >> a >> b;
        cout << "Case " << i << ": " << solve(a,b,0) << " " << solve(a,b,1) << "\n";
    }
}