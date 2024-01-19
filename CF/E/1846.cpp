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
ll exp_opt(ll n) {
    return 61.0 * log10(2)/log10(n);
}
ll fast_exp(ll n, ll k) {
    ll exp_o = exp_opt(n);
    k = min(k,exp_o);
    ll ans = 1;
    while (k) {
        if (k % 2 == 1) {
            ans *= n;
        }
        n *= n;
        k /= 2;
    }
    return ans;
}

ll root_n(ll b, ll exp) {
    ll low = 1,high = 1e9;
    while (low < high) {
        ll mid = low + (high - low)/2;
        if (exp * log10(mid) < log10(b))    low = mid + 1;
        else high = mid;
    }
    if (exp * log10(low) > log10(b))    low --;
    return low;
}
ll sum(ll b,ll k) {
    ll ans = 1;
    ll _b = b;
    for (int i = 1; i <= k; i ++) {
        ans += _b;
        _b *= b;
    }
    return ans;
}
bool f(ll n) {
    bool found = false;
    for (int i = 2; i < 61; i ++) {
        ll tmp_b = root_n(n,i);
        if (tmp_b > 1) {
            if (sum(tmp_b,i) == n)  return true;
        }
    }
    return found;
}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        ll n;   cin >> n;
        cout << (f(n)?"YES":"NO") << "\n";
    }
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)