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
int goodString(string s,char c){
    if (sz(s) == 1) {
        if (s[0] == c)    return 0;
        else return 1;
    }
    int mid = sz(s)/2;
    string l(s.begin(),s.begin() + mid);
    string r(s.begin() + mid,s.end());
    return min(goodString(l,c + 1) + goodString(r,c),goodString(l,c) + goodString(r,c + 1));
}
string res(string s) {
    if (sz(s) == 1) return s;
    int mid = sz(s) / 2;
    string l(s.begin(),s.begin() + mid);
    string r(s.begin() + mid,s.end());
    l = res(l);
    r = res(r);
    return min(l + r,r + l);
}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        int n;      cin >> n;
        string s;   cin >> s;
        char c = 'a';
        cout << goodString(s,c) << " ";
        string x = res(s);
        cout << " " << goodString(x,c) << "\n";
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)