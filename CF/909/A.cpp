#include<bits/stdc++.h>
using namespace std;
int main () {
    int tt; cin >> tt;
    while (tt --) {
        int n;  cin >> n;
        cout << (n%3?"First":"Second") << "\n";
    }
    return 0;
}