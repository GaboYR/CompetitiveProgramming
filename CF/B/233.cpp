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
int sum(ll n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
void f(ll n) {
    bool is = false;
    for(int i = 1; i <= 81; i ++) {
        //cout << i << "-------------\n";
        ll low = 1, high = 1e9;
        while (low < high) {
            //cout << low << " " << high << "\n";
            ll mid = low + (high - low)/ 2;
            if (mid * mid + i * mid < n)    low = mid + 1;
            else high = mid;
        }
        if (low * low + i * low < n)    low --;
        if (sum(low) == i && low * low + i * low == n) {
            is = true;
            cout << low << "\n";
            break;
        }  
    }
    if (!is)    cout << "-1\n";
}
int main(){
    fast_io
    ll n;   cin >> n;
    f(n);
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)