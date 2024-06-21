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
const int maxn = 5e4 + 1;
ld eps = 1e-5;
ld a[maxn];
ld diff[maxn];
bool f(ld R,ld pos,int n) {
    int ind = lower_bound(a,a + n, pos) - a;
    int left = ind - 1;
    int right = ind;
    bool is = false;
    ld r = R;
    ld tmp = pos;
    while (pos - r <= a[left] && left) {
        left --;
        pos = a[left];
        r -= 1;
    }
    r = R;
    pos = tmp; 
    while (pos + r >= a[right] && right < n) {
        right ++;
        pos = a[right];
        r -= 1;
    }
    cout << "IND: ";
    cout << left << " " << right << "\n";
    if (left == 0 and right == n)   return true;
    return false;
}
int main(){
    fast_io
    ifstream in("angry.in") ;
    ofstream out("angry.out");
    int n;  cin >> n;
    for (int i = 0; i < n; i ++)    cin >> a[i];
    sort(a, a + n);
    double pos = (a[0] + a[n - 1])/2;
    double R = (a[n - 1] - a[0]) / 2;
    ld low = 0,high = R;
    while (high - low > eps) {
        cout << low << " " << high << "\n";
        auto mid = low + (high - low) / 2;
        if (!f(mid,pos,n))   low = mid;
        else high = mid;
    }
    cout << fixed << setprecision(1);
    cout << high << "\n";
    cout << high << "\n";
    return 0;
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)