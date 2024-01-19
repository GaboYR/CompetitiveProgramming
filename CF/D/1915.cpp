#include<bits/stdc++.h>
using namespace std;
bool is_v(char c){
    return c == 'a' || c == 'e';
}
bool is_c(char c) {
    return !is_v(c);
}
int main () {
    ios_base::sync_with_stdio(0);   cin.tie(0);
    int TC; cin >> TC;
    while (TC --) {
        int len;    cin >> len;
        string s;   cin >> s;
        string res;
        int it_last = 0,it_curr = 0;
        int len = res.size();
        while (it_last < len) {
            if (!is_c(s[it_last])) {
                it_last = it_curr + 1;
            }
            if (is_v(s[it_last])) {
                it_last ++;
            }
            if (is_c(s[it_last])) {
                
            }
        }
    }
}