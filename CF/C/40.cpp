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
ll n,x,m,y;
ll ans,curr;
int main(){
    fast_io
    cin >> n >> x >> m >> y;
    int _x = x - n;
    int x_ = x + n;
    int _y = y - m;
    int y_ = y + m;
    if (_y >= x_ || y_ <= _x) {
        ans = m + n + 1;
    }
    else {
        ans = m + n + min(m,n) * min(m,n) + 1;
    }
    cout << ans << "\n";
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)