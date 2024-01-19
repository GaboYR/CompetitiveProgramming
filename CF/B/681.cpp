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

int main(){
    fast_io
    int n;  cin >> n;
    int c = 1234,b = 123456,a =1234567;
    int ans = 0;
    for (int i = 0; i * a <= n; i ++) {
        for (int j = 0; j * b + i * a <= n; j ++) {
            int k = n - b * j - i * a;
            if (k % c == 0){
                ans ++;
            }
        }
    }
    cout << (ans?"YES":"NO")<< "\n";
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)