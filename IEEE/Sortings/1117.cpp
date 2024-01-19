#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int cnt[4];
int x,y,p,q,len;
int X,Y;
int cx,cy;
string s;
int f (int m) {
    memset(cnt,0,sizeof cnt);
    int d = m / len;
    int r = m % len;
    cx = X * d;
    cy = Y * d;
    for (int i = 0; i < r; i ++) {
        if (s[i] == 'U')   cy ++;
        if (s[i] == 'D')   cy --;
        if (s[i] == 'L')   cx --;
        if (s[i] == 'R')   cx ++;
    }
    if (abs(x - p) <= abs(cx) && abs(y - q) <= abs(cy))    return 1;
    return 0;

}
int main () {
    cin >> x >> y;
    cin >> p >> q;
    cin >> len;
    for (int i = 0; i < len; i ++)  {
        char c; cin >> c;
        if (c == 'U')   cy ++;
        if (c == 'D')   cy --;
        if (c == 'L')   cx --;
        if (c == 'R')   cx ++;
        s += c;
    }
    X = cx;
    Y = cy;
    int low = 0,high = 2e9 + 10;
    while (low < high) {
        cout << low << ' ' << high << '\n';
        int mid = low + (high - low) / 2;
        if (f(mid)) low = mid;
        else high = mid - 1;
    }
    return 0;
}