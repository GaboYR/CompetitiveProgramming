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
struct Req{
    int t,z,y;
};
Req req[1000];
//en un tiempo T,se habran hecho x globos
ll balls(ll T) {
    
}
int main(){
    fast_io
    int m,n;    cin >> m >> n;
    for (int i = 0; i < n; i ++) {
        cin >> req[i].t >> req[i].y >> req[i].z;
    }
    
    return 0;

}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)