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
int main(){
    fast_io
    int n;  cin >> n;
    if (n == 1) {
        cout << "1\n9\n0\n-72\n";
    }
    else if (n == 2) {
        cout << "50\n19\n25\n-63\n";
    }
    else {
        //nro 1
        int num = 950;
        int nro9 = n - 3;
        while (nro9 --) cout << "9";
        cout << num << "\n";

        //nro 2
        cout << "1";
        int nro0 = n - 2;
        while (nro0 --) cout << "0";
        cout << "9";
        cout << "\n";
        //nro 3

        if (n > 9) {
            nro9 = n - 9;
            while (nro9 --) cout << "9";
            ll res = 999999999;
            cout << res - 81 * (n - 2) - 25 << "\n";
        }
        else {
            ll res = 950;
            ll b = 1000;
            int nro9ad = n - 3;
            while (nro9ad --) {
                res = res + 9 * b;
                b *= 10;
            }
            cout << res - 81 * (n - 2) - 25 << "\n";
        }
        //nro4
        nro9 = n - 3;
        while (nro9 --) {
            cout << "9";
        }
        cout << 27 <<"\n";
    }
    return 0;
}
