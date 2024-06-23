#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    bool first = false;
    while (cin >> n,n) {
        if (!first) {
            first = true;
        }
        else {
            cout << '\n';
        }
        bool found = false;
        for (int fghij = 1234; fghij <= 98765 / n; fghij ++) {
            int abcde = fghij * n;
            int tmp, used = (fghij < 10000);
            tmp = abcde;
            while (tmp) {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            tmp = fghij;
            while (tmp) {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            if (used == (1 << 10) - 1) {
                found = true;
                cout << setw(5) << setfill('0') << abcde << " / " << setw(5) << setfill('0') << fghij << " = " << n << '\n';
            }
        }
        if (!found) {
            cout << "There are no solutions for " << n << ".\n";
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}