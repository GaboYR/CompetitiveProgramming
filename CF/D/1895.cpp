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
const int maxn = 2e5 + 1;
int a[maxn],b[maxn];
int main(){
    fast_io
    int n;  cin >> n;
    for (int i = 1; i < n; i ++)    cin >> a[i];
    b[0] = a[1];
    b[1] = 0;
    for (int i = 2; i < n; i ++) {
        b[i] = a[i]^b[i - 1];
    }
    for (int i = 0; i < n; i ++) {
        cout << b[i] << " ";
    }
    return 0;
}