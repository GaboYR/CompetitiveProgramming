#include<bits/stdc++.h>
using namespace std;
int main () {
    long long n,k; cin >> n >> k;
    int cont = 1;
    while (k % 2 == 0) {
        cont ++;
        k /= 2;
    }
    cout << cont << "\n";
    return 0;
}