#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define cin std::cin
using ll = long long;
using ld = long double;
using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;
const int maxn = 1e5 + 1;
int col[maxn],cont[maxn];
int main(){
    fast_io
    int l,c,n;  cin >> l >> c >> n;
    for (int i = 1; i <= c; i ++) {
        cont[i] = 0;
    }
    for (int i = 0; i < l; i ++) {
        col[i] = 1;
        cont[col[i]] ++;
    }
    for (int i = 0; i < l; i ++) {
        cout << i << " \n"[i == l - 1];
    }
    while (n --) {
        ll p,x,a,b;    cin >> p >> x >> a >> b;
        ll s = cont[p];
        ll m1 = (a + s * s) % l;
        ll m2 = (m1 + 2 * b * s + b * b) % l;
        if (m1 > m2)    swap(m1,m2);
        
        for (int i = m1; i <= m2; i ++) {
 
            cont[col[i]]--;
            col[i] = x;
            cont[x] ++;
            
        }
        for (int i = 0; i < l; i ++) {
            cout << col[i] << " \n"[i + 1 == l];
        }
    }
    cout << *max_element(cont,cont + maxn);
    return 0;
}