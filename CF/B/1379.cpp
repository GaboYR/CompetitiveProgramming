#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0)
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
//  l <= a <= b <= c <= r
//  m = n * a + b - c
//  n = (m + c - b) / a;
int main(){
    fast_io;
    int TC; cin >> TC;
    while(TC --){
        ll l,r,m;  cin >> l >> r >> m;
        ll a,b,c;
        ll low = max(1ll,m + l - r), high = m + r - l;
        for (ll i = low; i < high; i ++) {
            
        }
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)