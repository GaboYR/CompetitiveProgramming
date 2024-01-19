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

bool solve(){
    string s;   cin >> s;
    int n= (int)s.size();
    set<char>ss;
    int count=0;
    for (int i = 0; i < n/2; i++) {
        if(count>2) return 0;
        if(s[i] != s[n-1-i]){
            ss.insert(s[i]);
            ss.insert(s[n-1-i]);
            count++;   
        }
    }
    if (count == 0) return 1;
    if(ss.size() == 2 && count == 2 )return true;
    ss.insert(s[n/2]);
    if(n & 1 and ss.size() == 2 and count == 1 )return true;
    
    return false;
}
int main(){
    fast_io
    if(solve()){
        cout<<"YES\n";
    }else cout<<"NO\n";

    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)  