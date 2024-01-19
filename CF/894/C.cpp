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
    int tt; cin >> tt;
    while (tt --) {
        char table[10][10];
        int ans = 0;
        for (int i = 0; i < 10; i ++) {
            for (int j = 0; j < 10; j ++) {
                cin >> table[i][j];
                if (table[i][j] == 'X') {
                    if (i == 0 || i == 9 || j == 0 || j == 9)   ans += 1;
                    else if (i == 1 || i == 8 || j == 1 || j == 8)  ans += 2;
                    else if (i == 2 || i == 7 ||  j == 2 || j == 7) ans += 3;
                    else if (i == 3 || i == 6 || j == 3 || j == 6)  ans += 4;
                    else ans += 5;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)