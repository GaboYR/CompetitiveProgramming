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
    int n;  cin >> n;
    cin.ignore();
    for (int  i = 0; i < n; i ++) {
        string s;
        getline(cin,s);
        int cont[7] = {0};
        for (int i = 0; i < sz(s); i ++){
            if (s[i] == 'a')    cont[0] ++;
            if (s[i] == 'b')    cont[1] ++;
            if (s[i] == 'c')    cont[2] ++;
            if (s[i] == 'd')    cont[3] ++;
            if (s[i] == 'e')    cont[4] ++;
            if (s[i] == 'f')    cont[5] ++;
            if (s[i] == 'g')    cont[6] ++;
        }
        char res = 'a';
        int val = cont[0];
        for (int i = 0; i < 7; i ++) {
            //cout << cont[i] << " ";
            if (cont[i] > val) {
                res = char('a' + i);
                val = cont[i];
            }
        }
        cout << char(toupper(res));
        cout << "\n";
        for (int i = 0; i < 7; i ++)    cont[i] = 0;
    }
    return 0;
}