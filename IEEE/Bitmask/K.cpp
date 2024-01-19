#include<bits/stdc++.h>
using namespace std;
long long xor_ranges(long long a) {
    int mod = a % 4;
    if (mod == 0)   return a;
    if (mod == 1)   return 1;
    if (mod == 2)   return a + 1;
    else            return 0;
}
long long solve(long long a,long long b) {
    if (a == b) return a;
    else return xor_ranges(b)^xor_ranges(a - 1);
}
int main () {
    long long a,b;  cin >> a >> b;
    cout << solve(a,b) << "\n";
}