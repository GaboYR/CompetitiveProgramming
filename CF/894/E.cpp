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
const int maxn = 2e5 +3;
int a[maxn];
int n,x;
ll f(int mid) {
    ll ans = 0;
    for (int i = 0; i < n; i ++) {
        if (mid > a[i]) ans += mid - a[i];
    }
    return ans;
}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        cin >> n >> x;
        for (int i = 0; i < n; i ++)    cin >> a[i];
        int low = 1,high = 2e9;
        while (low < high) {
            //cout << low << " " << high << "\n";
            int mid = low + (high - low)/2;
            if (f(mid) < x) low = mid + 1;
            else high = mid; 
        }
        if (f(low)> x)  low --;
        cout << low << "\n";
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)