#include<bits/stdc++.h>
using namespace std;
int dig(int n){
    int res = 0;
    do{
        res ++;
        n /= 10;
    } while (n);
    return res;
}
string parsing(int nro_digits, int value) {
    int digs = dig(value);
    string res = to_string(value);
    while (digs < nro_digits) {
        res = "0" + res;
        digs ++;
    }
    return res;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<int,vector<string>> mp;
    int l = 0, h = 10;
    for (int digits = 1; digits <= 4;digits ++) {
        for (int i = l; i < h; i ++) {
            for (int j = l; j < h; j ++) {
                if ((i + j) * (i + j) == (i * h + j)) {
                    string res = parsing(digits,i) + parsing(digits,j);
                    mp[digits].push_back(res);
                }
            }
        }
        h = h * 10;
    }
    while (cin >> n) {
        for (auto e : mp[n / 2]) {
            cout << e << '\n';
        }
    }
}