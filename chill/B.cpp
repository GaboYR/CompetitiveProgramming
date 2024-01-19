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
    int n; cin >> n;
    vector<int> v1;
    vector<int> v2;
    for (int i=0; i<n; i++) {
        int t,x,y; 
        cin >> t >> x >> y;
        if (t == 1) v1.push_back(x-y);
        if (t == 2) v2.push_back(x-y);
    }
    sort(all(v1));
    sort(all(v2));
    int pos_x = 1, pos_y = 1;
    for (int e : v1) pos_x += e;
    for (int e : v2) pos_y += e;
    if (pos_x <= 0 or pos_y <= 0) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        cout << "(" << pos_x << ", " << pos_y << ")\n";
    }
    return 0;
}
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)