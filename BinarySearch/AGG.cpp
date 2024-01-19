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
const int maxn = 1e5 + 2;
int a[maxn];
int f(int m, int n) {
    int ans = 1;
    int it = 0;
    int pos = it + 1;
    while (pos < n) {
        if (a[pos] - a[it] < m) pos ++;
        else {
            ans ++;
            it = pos;
            pos ++;
        }
    }
    return ans;
}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        int n,c;    cin >> n >> c;
        for (int i = 0; i < n; i ++)    cin >> a[i];
        sort(a, a + n);
        int low = 0,high = a[n - 1] - a[0];
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (f(mid,n) < c) {
                high = mid;
            }
            else low = mid + 1;
        }
        if (f(low,n) < c) low --;
        cout << low <<"\n";
    }
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)