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
const int maxn = 2e5 +3;
int cont1[maxn],cont2[maxn];
int diff (int i) {
    return cont1[i] - cont2[i];
}
int diff_ij(int i,int j) {
    return diff(j) - diff (i - 1);
}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        // int n;  cin >> n;
        // for (int i = 0; i < 2 * n; i ++) {
        //     cin >> a[i];
        //     if (a[i] == 1) {
        //         dp[i + 1] = dp[i];
        //     }
        //     else {
        //         dp[i + 1] = dp[i] + 1;
        //     }
        // }
        // int diff = 2 * n - 2 * dp[2 * n];
        // for (int i = 1; i <= 2 * n; i ++) {
        //     cout << dp[i] << " ";
        // }
        // cout << "\n";
        // map<int,ii> mp;
        // int val_it = dp[1];
        // for (int i = 1; i <= 2 * n;) {
        //     int f,s;
        //     f = i;
        //     while (dp[i] == val_it) {
        //         i ++;
        //         if (dp[i] != val_it) {
        //             s = i - 1;
        //         }
        //     }
        //     if (f == 2* n) s = f;
        //     mp[val_it] = ii(f,s);
        //     val_it ++;
        // }
        // for (auto e:mp) {
        //     cout << e.first << ": " << e.second.first << " " << e.second.second << "\n";
        // }
        
        int n;  cin >> n;
        n *= 2;
        int c1 = 0,c2 = 0;
        for (int i = 1;i <= n; i ++) {
            char num;   cin >> num;
            if (num == '1') c1 ++;
            else            c2 ++;
            cont1[i] = c1;
            cont2[i] = c2;
        }
        // for (int i = 1; i <= n; i ++) {
        //     cout << cont1[i] << " ";
        // }
        // cout << "\n";
        // for (int i = 1; i <= n; i ++) {
        //     cout << cont2[i] << " ";
        // }
        // cout << "\n";
        
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)