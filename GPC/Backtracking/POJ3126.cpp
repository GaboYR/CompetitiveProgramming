#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int a,b;
bool criba[10000];
int p1[4],p2[4];
bool vis[10000];
vector<int> primes;
vector<int> primes_diff_one_digit(int pr) {
    vector<int> res;
    for (int i = 0; i < primes.size(); i ++) {
        int dif = 0;
        int p = primes[i];
        while (p > 10) {
            dif += (p % 10 == pr % 10);
            p /= 10;
            pr /= 10;
        }
        if (dif == 1) {
            //cout << primes[i] << '\n'; 
            vis[p] = 1;
            res.push_back(p);
        }
    }
    return res;
}
void back(int a,int c) {
    if (a == b) {
        cout << c << '\n';
        return;
    }
    vector<int> res = primes_diff_one_digit(a);
    for (auto e : res) {
        cout << e << ' ';
    }
    for (auto r : res) {
        back(r,c + 1);
    }
}
int main () {
    for (int i = 0; i < 10000; i ++)    criba[i] = 1;
    criba[0] = criba[1] = 0;
    for (int i = 2; i < 10000; i ++) {
        if (criba[i]) {
            if (i > 1000) primes.push_back(i);
            for (int j = 2; i * j < 10000; j ++) {
                criba[i * j] = 0;
            }
        }
    }
    //for (auto p : primes) cout << p << "\n";
    int TC; cin >> TC;
    while (TC --) {
        memset(vis,0,sizeof vis);
        cin >> a >> b;
        back(a,0);
    }
    return 0;
}