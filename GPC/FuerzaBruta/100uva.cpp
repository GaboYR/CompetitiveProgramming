#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define cin std::cin
#define cout std::cout
using ll = long long;
using ld = long double;
using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;
int cycle(int n) {
    int cont = 1;
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = 3 *n + 1;
        cont ++;
    }
    return cont;
}
int main(){
    fast_io
    int a,b;
    while (cin >> a >> b) {
        int res = 0;
        for (int i = min(a,b); i <= max(a,b); i ++) {
            if ((res) < cycle(i)) {
                res = cycle(i);
            }
        }
        cout << a << " " << b << " " << res << "\n";
    }
    return 0;
}