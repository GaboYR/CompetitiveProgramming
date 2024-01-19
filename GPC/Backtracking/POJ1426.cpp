#include<iostream>
#include<cstring>
using namespace std;
int n;
bool res[204];
/*
f(1,n,0) -> f(10,n,1) -> 
          -> f(11,n,0) 
*/
void back(int b,int r) {
    if (r > 20)    return;
    if (b == 0) {
        cout  << r << "\n";
        return;
    }
    for (int i = 0; i < 2; i ++) {
        back((b * 10 + i) % n, r + 1);
    }
}
int main () {
    while (cin >> n,n) {
        memset(res,0,sizeof res);
        back(1,0);
    }
    return 0;
}