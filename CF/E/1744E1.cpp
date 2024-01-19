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
vi desc(ll n) {
    vi res;
    for (ll i = 1; i * i <= n; i ++) {
        if (n % i == 0){
            res.push_back(i);
            if (i != n/i) {
                res.push_back(n/i);
            }
        }
    }
    sort(all(res));
    return res;
}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        ll a,b,c,d;    cin >> a >> b >> c >> d;
        vi prod = desc(a*b);
        for (int i = 0; i < sz(prod); i ++) {
            
        }
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)