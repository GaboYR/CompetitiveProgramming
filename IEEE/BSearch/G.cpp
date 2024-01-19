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
int f(int &n,int &x,int &y) {
    if (x < y)  return n / x + (n - x)/y;
    return n / y + (n - y)/x; 
}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        int n,x,y;  cin >> n >> x >> y;
        int low = 0, high = 2e9;
        while (low < high) {
            //cout << low << " " << high << "\n";
            int mid = low + (high - low)/2;
            if (f(mid,x,y) < n)  low = mid + 1;
            else high = mid;
        }
        cout << low << "\n";
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)