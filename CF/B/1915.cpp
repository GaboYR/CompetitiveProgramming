#include<bits/stdc++.h>
using namespace std;
int main () {
    int TC; cin >> TC;
    TC *= 3;
    while (TC --) {
        int res = 0;
        string s;   cin >> s;
        for (int i = 0; i < 3; i ++) {
            if (s[i] == 'A')   res ^= 1;
            if (s[i] == 'B')   res ^= 2;
            if (s[i] == 'C')   res ^= 3;
        }
        if (res != 0)   cout << char(res + 'A'- 1) << '\n';  
    }
}