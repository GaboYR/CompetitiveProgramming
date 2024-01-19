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
        int n;  cin >> n;
        n *= 2;
        int c1 = 0,c2 = 0;
        map<int,vi> mp;
        int cont = 0;
        for (int i = 1;i <= n; i ++) {
            char num;   cin >> num;
            if (num == '1') {
                cont ++;
                mp[cont].emplace_back(i);
            }
            else {
                cont --;
                mp[cont].emplace_back(i);
            }
        }
        for (auto e:mp){
            cout << e.first << ": ";
            for (auto ee:e.second) {
                cout << ee << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)