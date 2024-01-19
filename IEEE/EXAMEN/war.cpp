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
map<char,int> mp;
void solve(queue<char> &q1,queue<char> &q2,int it){
    while (!q1.empty() && !q2.empty() && it --) {
        char c1 = q1.front();   q1.pop();
        char c2 = q2.front();   q2.pop();
        if (mp[c1] == mp[c2]) {
            q1.push(c1);
            q2.push(c2);
        }
        else if (mp[c1] > mp[c2]) {
            q1.push(c2);
        }
        else {
            q2.push(c1);
        }
    }
    if (q1.empty()) {
        cout << "player 2\n";
    }
    else if (q2.empty()) {
        cout << "player 1\n";
    }
    else cout << "draw\n";
}
int main(){
    fast_io
    mp['2'] = 2;
    mp['3'] = 3;
    mp['4'] = 4;
    mp['5'] = 5;
    mp['6'] = 6;
    mp['7'] = 7;
    mp['8'] = 8;
    mp['9'] = 9;
    mp['T'] = 10;
    mp['J'] = 11;
    mp['Q'] = 12;
    mp['K'] = 13;
    mp['A'] = 14;
    int tt; cin >> tt;
    cin.ignore();
    while (tt --) {
        string sa,sb;
        getline(cin,sa);
        getline(cin,sb);
        queue<char> q1, q2;
        istringstream iss(sa),iss2(sb);
        char tmp;
        while (iss >> tmp) {
            q1.push(tmp);
        }
        while (iss2 >> tmp) {
            q2.push(tmp);
        }
        solve(q1,q2,1000);
    }
    return 0;
}