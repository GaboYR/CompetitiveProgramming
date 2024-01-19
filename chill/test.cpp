#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x) {
    ll s=0;
    while(x!=0) {
        s += (x%10) * (x%10);
        x/=10;
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    for (ll i = pow(10,n-1); i < pow(10,n); i++) {
        cout << i << " => " << i - f(i) << endl; 
    }
    return 0;
}