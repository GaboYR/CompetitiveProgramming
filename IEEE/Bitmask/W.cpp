#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 2;
int a[maxn];
int main() {
    int sum,lim;  cin >> sum >> lim;
    vector<pair<int,int>> v;
    for (int i = 1; i <= lim; i ++) {
        a[i] = i&-i;
        //cout << a[i] << " ";
        v.emplace_back(make_pair(a[i],i));
    }
    sort(v.rbegin(),v.rend());
    set<int> s;
    for (int i = 0; i < size(v); i ++) {
        if (v[i].first > sum) i++;
        else {
            s.insert(v[i].second);
            sum -= v[i].first;
        }
    }
    if (sum == 0) {
        cout << s.size() << "\n";
        for (auto e:s)  cout << e << " ";
    }
    else cout << "-1";
    cout << "\n";
    return 0;
}