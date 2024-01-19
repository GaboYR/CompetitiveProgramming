#include<bits/stdc++.h>
using namespace std;
int n;
//pair <indice , primo>
vector<pair<int,int>> primes;
vector<int> sol;
int used[20];
int prime[32];
int bitmask;
void init() {
    prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = 
    prime[17] = prime[19] = prime[23] = prime[29] = prime[31] = 1;
}
void print() {
    for (int i = 0; i < sol.size(); i ++) {
        cout << sol[i] << " \n"[i == sol.size() - 1];
    }
}
bool validate(int num) {
    if (used[num])  return false;
    if (sol.size() <= 1)    return true;
    int p1 = sol[sol.size() - 1] + sol[sol.size() - 2];
    int p2 = sol[0] + sol[sol.size() - 1];
    return prime[p1];
}
void back(int num) {
    if (num == n) {
        if (n == 1) print();
        else {
            if (prime[sol[0] + sol[n - 1]] && prime[sol[n - 1] + sol[n - 2]]){
                print();
            }
        }
    }
    else {
        for (int i = 2; i <= n; i ++) {
            if (validate(i)) {
                sol.emplace_back(i);
                used[i] = 1;
                back(num + 1);
                used[i] = 0;
                sol.pop_back();
                
            }
        }
    }

}
int main () {
    init();
    int cnt = 1;
    while (cin >> n) {
        sol.emplace_back(1);
        if (cnt != 1)cout << "\n";
        cout << "Case " << cnt ++ << ":\n";
        back(1);
        sol.clear();
    }
    return 0;
}