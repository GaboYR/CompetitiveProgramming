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
        string s;   cin >> s;
        int ans = 0;
        for (int i = 0; i < sz(s); i ++) {
            ans += (s[i] - 'a'==  i);
        }
        if (ans != 0)   cout << "YES\n";
        else cout << "NO\n";
    }
    

    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)