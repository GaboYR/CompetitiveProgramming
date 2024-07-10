#include<bits/stdc++.h>
using namespace std;
string s;
int n, k;

bool validate(string s) {
    int cont[4];
    
    memset(cont,0,sizeof(cont));
    
    for (int i = 0; i < s.size(); i ++) cont[s[i] - 'a'] ++;
    
    for (int i = 0; i < 4; i ++) 
        if (cont[i] == 1) return false;
    
    return true;
}
void bt(int b,int k) {
    if (b == n) {
        if (validate(s))    cout << s << '\n';
        return;
    }
    for (int i = 0; i < k; i ++) {
        s.push_back(char('a' + i));
        bt(b + 1, k);
        s.pop_back();
    }
}
void solve () {
    cin >> n >> k;
    bt(0, k);
    cout << "---\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt;
    cin >> tt;
    
    while (tt --)    solve ();
    
    return 0;
}