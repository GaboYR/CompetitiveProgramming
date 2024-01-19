#include<bits/stdc++.h>
using namespace std;
int main () {
    int n,q;    cin >> n >> q;
    string s;   cin >> s;
    int x[10];
    while (q --) {
        int l,r;    cin >> l >> r;
        l --;
        r --;
        string tmp(s.begin() + l,s.begin() + r + 1);
        r -= l;
        l = 0;
        //cout << tmp << "\n";
        int curr,last;
        curr = last = l;
        int p = 0,dp = 1;
        memset(x,0,sizeof x);
        while (curr >= l && curr <= r) {
            //cout << curr << " " << tmp[curr] << "\n";
            if (tmp[curr] >= '0' && tmp[curr] <= '9') {
                x[tmp[curr] - '0'] ++;
                if (tmp[curr] != '0')   tmp[curr] --;
                else tmp[curr] = '*';
                p = 0;
                last = curr;
            }
            if (tmp[curr] == '<') {
                dp = 0;
                if (p) tmp[last] = '*';
                p = 1;
                last = curr;
            }
            if (tmp[curr] == '>') {
                dp = 1;
                if (p)  tmp[last] = '*';
                p = 1;
                last = curr;
            }
            if (dp) curr ++;
            else curr --;
        }
        for (int i = 0; i < 10; i ++)   cout << x[i] << " \n"[i == 9];
    }
    return 0;
}