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
bool Diff(int n) {
    int u = n % 10; n /= 10;
    int d = n % 10; n /= 10;
    int c = n % 10; n /= 10;
    int um = n % 10;
    return (u != d && u != c && u != um && d != c && d != um && c != um);
}
int main(){
    fast_io
    int n;  cin >> n;
    n ++;
    while (!Diff(n)) n ++;
    cout << n << "\n";
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)