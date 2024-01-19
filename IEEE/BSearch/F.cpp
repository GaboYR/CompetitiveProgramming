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
const int maxn = 1e6 + 3;
int a[maxn];
int n,k;
const ld eps = 1e-8;
int f(ld m) {
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        ans += int(a[i]/m);
    }
    return ans;
}
int main(){
    fast_io
    cin >> n >> k;
    for (int i = 0; i < n; i ++)    cin >> a[i];
    ld low = 1.0,high = 1e18;
    while (high - low > eps) {
        //cout << low << " " << high << "\n";
        ld mid = low + (high - low) /2.0;
        if (f(mid) >= k) low = mid;
        else high = mid;
    }
    cout << fixed << setprecision(8) << high << "\n";
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)