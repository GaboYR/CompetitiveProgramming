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
    int tt;  cin >> tt;
    int n;    
    string s;
    while (tt --) {
        cin >> n;
        cin.ignore();
        cin.ignore();
        getline(cin,s);

        istringstream iss(s);
        string word;
        bool the = false;
        bool is = false;
        while (iss >> word && !is) {
            if (word == "the") {
                the = true;
                is = true;
            }
        }
        for (auto ch:s) {
            if (ch != ' '){
                if (the) {
                    int v = ch;
                    v -= n;
                    if (v < 'a'){
                        v += 26;
                    }
                    ch = v;            
                }
                else {
                    int v = ch;
                    v += n;
                    if (v > 'z') {
                        v -= 26;
                    }
                    ch = v;
                }
            }
            
        }
        cout << s << "\n";
        the = false;
    }
    
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)