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
const int maxn = 103;
int a[maxn][maxn],dp[maxn][maxn];
int main(){
    fast_io
    int n;  cin >> n;
    for(int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            dp[i + 1][j + 1] += dp[i][j] + a[i][j - 1] + a[i ][j];
        }
    }
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= n; j ++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)