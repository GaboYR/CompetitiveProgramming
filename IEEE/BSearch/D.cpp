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
const int maxn = 1e5 + 2;
int a[maxn];
int main(){
    fast_io
    int n;  cin >> n;
    for (int i = 0; i < n; i ++)    cin >> a[i];
    sort(a,a + n);
    int q;  cin >> q;
    while (q --) {
        int l,r;    cin >> l >> r;
        cout <<  lower_bound(a,a + n, r + 1)  - lower_bound(a,a + n,l) << " ";
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)