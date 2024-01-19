#include<bits/stdc++.h>
using namespace std;
#define sz(v)   (int)v.size()
int n;
vector<pair<int,int>> primes;
vector<int> sol;
int prime[32];
int bitprimes = (1<<1)|(1<<2)|(1<<4)|(1<<6)|(1<<10)|(1<<12)|(1<<16)|(1<<18)|(1<<22)|(1<<28)|(1<<30);
int bitmask = (1<<n) - 1;
void print() {
    for (int i = 0; i < sz(sol); i ++) {
        cout << sol[i] << " \n"[i == sol.size() - 1];
    }
}
bool validate(int num) {
    if (bitmask&(1<<num))  return false;
    int s = sz(sol);
    if (s <= 1)    return true;
    int p1 = sol[s - 1] + sol[s - 2];
    return bitprimes&(1<<p1 - 1);
}
void back(int mask) {
    print();
    if (mask == bitmask) {
        if (n == 1) print();
        else {
            int p1 = sol[0] + sol[n - 1];
            int p2 = sol[n - 1] + sol[n - 2];
            if (bitprimes&(1<<p1 - 1) && bitprimes&(1<<p2 - 1)){
                print();
            }
        }
        return;
    }
    else {
        for (int i = 2; i <= n; i ++) {
            if (validate(i)) {
                sol.emplace_back(i);
                mask|=(1<<i - 1);
                back(mask);
                mask&=~(1<<i - 1);
                sol.pop_back();
            }
        }
    }
}
int main () {
    int cnt = 1;
    while (cin >> n) {
        sol.emplace_back(1);
        if (cnt != 1)cout << "\n";
        cout << "Case " << cnt ++ << ":\n";
        back(0);        
    }
    return 0;
}