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
void print(priority_queue<int> pq){
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}
int main(){
    fast_io
    int tt; cin >> tt;
    while (tt --) {
        int n;  cin >> n;
        priority_queue<int> q0,q1;
        for (int i = 0; i < n; i ++) {
            char c; cin >> c;
            if (c == '1')   q1.push(i);
            else q0.push(i);
        }
        ll ans = 0;
        while (n --) {
            if (q0.empty()) cout << "-1 ";
            else {
                if (q0.top() == n) {
                    q0.pop();
                }
                else {
                    ans += q1.top() - q0.top() + 0ll;
                    int t = q0.top();
                    q1.pop();
                    q0.pop();
                    q1.push(t);
                }
                cout << ans << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}