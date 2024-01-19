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
ld ggg(ld a,ld b) {
    if (b == 0) return a;
    return (ggg(b,fmod(a,b)));
}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --){
        ld alfa;    cin >> alfa;
        ll x;
        auto g = ggg(alfa,90);
        cout << fixed;
        cout << setprecision(100) << alfa/g << "\n";
    }
    return 0;
}