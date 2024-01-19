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

int main(){
    fast_io
    int n,a,b,c;    cin >> n >> a >> b >> c;
    int ans = 0;
    for (int i = 0; i/2 <= n && i <= a ; i += 2) {
        for (int j = 0; j + i/2 <= n && j <= b; j ++) {
            int k = (n - i/2 - j)/2;
            if (i/2 + j + 2 * k == n && k <= c) {
                //cout << i << " " << j << " " << k << "\n";
                ans ++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)