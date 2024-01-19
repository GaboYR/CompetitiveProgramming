#include<bits/stdc++.h>
using namespace std;
#define sz(v) v.size()
int cont = 1;
void printSet(vector<int> &v) {
    bool first = false;
    cout << "{";
    for (int i = 0; i < sz(v); i ++) {
        cout << v[i];
        if (i != sz(v) - 1) {
            cout << ",";
        }
    }
    cout << "}\n";
}
void backtracking(vector<int> &v,vector<int> &res,int ind) {
    cout << cont ++ << ": ";
    printSet(res);
    for (int i = ind; i < sz(v); i ++) {
        res.emplace_back(v[i]);
        backtracking(v,res,i + 1);
        res.pop_back();
    }
}
int main() {
    int n;  cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i ++) {
        cin >> v[i];
    }
    vector<int> res;
    int cont = 1;
    backtracking(v,res,0);
    return 0;
}