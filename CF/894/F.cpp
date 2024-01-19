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
const int maxn = 2e5 +4;
int trees[maxn],fruit[maxn];
int n,k;
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        cin >> n >> k;
        for (int i = 0; i < n; i ++)    cin >> fruit[i];
        for (int i = 0; i < n; i ++)    cin >> trees[i];
        int it = 0;
        int f = 0;
        while (it < n) {
            int tmp = it;
            if(trees[tmp] % trees[it] != 0) it ++;
            else {
                while (trees[tmp] % trees[it] == 0) tmp ++;
            }
            
            cout << it << " "  << tmp;
            it = tmp;
        }
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)