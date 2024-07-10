#include<bits/stdc++.h>
using namespace std;
long long n;
vector<int> number;
bool found = false;
int cont[10];
bool check(int val) {
    return cont[val] < 2;
}
long long bt(int pos, bool val,long long num) {
    if (found) return -1;
    if (pos == number.size()) {
        found = true;
        return num;
    }
    if (val) {
        for (int i = number[pos]; i >= 0; i --) {
            if (!check(i)) continue;
            cont[i] ++;
            long long res = bt(pos + 1, i == number[pos],num * 10 + i);
            cont[i] --;
            if (res > 0)    return res;
        }
    }
    else {
        for (int i = 9; i >= 0; i --) {
            if (!check(i)) continue;
            cont[i] ++;
            long long res = bt(pos + 1, false,num * 10 + i);
            cont[i] --;
            if (res > 0)    return res;
        }
    }
    return -1;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        number.clear();
        while (n) {
            number.push_back(n % 10);
            n /= 10;
        }
        reverse(number.begin(),number.end());
        found = false;
        cout << bt(0,true,0) << '\n';
    }
}