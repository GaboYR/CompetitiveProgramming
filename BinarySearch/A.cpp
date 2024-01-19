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
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int Sz; cin >> Sz;
    string s;   cin >> s;
    x1 -= x2;
    y1 -= y2;
    char dx,dy;
    if (x1 > 0) dx = 'R';
    else if (x1 < 0)    dx = 'L';
    if (y2 > 0) dy = 'U';
    else if (y2 < 0)    dy = 'D';
    
    
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)