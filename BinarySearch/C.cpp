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
ll n,x,y,c;
ll numb(ll num) {
    return (num + 1) * (num + 2)/ 2;
}
ll count(ll it,ll x,ll y,ll limx,ll limy) {
    if (it < 0) return 0;
    
}
ll f(int m) {
    return  count(m, x, y , n, 1) +
            count(m - 1, x - 1, y, 1, 1) + 
            count(m - 2, x - 1, y + 1, 1, n) + 
            count(m - 1, x, y + 1, n, n);
}
int main(){
    fast_io
    cin >> n >> x >> y >> c;
    int low = 0,high = 2 * n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (f(mid) > c)   low = mid + 1;
        else high = mid;
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)