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
ll f(int w, int h, ll n) {
    ll ans =  1ll * (n / h) * (n / w);
    if (ans < 0)    return 4e18;
    return ans;
}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        int w,h,n;  cin >> w >> h >> n;
        ll low = 0,high = 1e14;
        while (low < high) {
            //cout << low << " " << high << "\t";
            ll mid = low + (high - low) / 2;
            //cout << f(w,h,mid) << "\n";
            if (f(w,h,mid) < n) {
                low = mid + 1;
            }
            else high = mid;
        }
        cout << low << "\n";
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)