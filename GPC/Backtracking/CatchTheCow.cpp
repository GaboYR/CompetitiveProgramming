#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 3;
int a[maxn];
int p[maxn];
int pre[maxn];
int n,k;
int cont = 10;
queue<int> q;
bool check(int n) {
    if (n < 1)  return false;
    if (n > 1e5)    return false;
    if (2 * n > 2e5) return false;
    return true;
}
void add(int n,int ans,int op, int ant) {
    if (check(n)) {
        if (!a[n]) {
            a[n] = ans;
            p[n] = op;
            pre[n] = ant;
        }
        //else a[n] = min(a[n],ans);
        q.push(n);
    }
    return;
}
void dfs(int n,int ans) {
    if (n > k) {
        cout << n - k << "\n";
        return;
    }
    if (a[k])         cout << a[k] - a[n];
    if (!a[n]) a[n] = ans;
    q.push(n);
    while (!a[k]) {
        int s = q.size();
        ans ++;
        while(s --) {
            int e = q.front();
            //cout << e << " " << a[e] << "\n";
            q.pop();
            if (!a[e * 2])  add(2 * e,ans ,2, e);
            if (!a[e + 1])  add(e + 1,ans ,1, e);
            if (!a[e - 1])  add(e - 1,ans ,-1, e);
            //cout << "\n-----------------\n";
        }
    }
    //cout << a[k] - a[n] << "\n";
    int f = k;
    while (k != n) {
        cout << k << " " << p[k] << "\n";
        k = pre[k];
    }
    cout << k << "\n";
}
int main(){
    memset(p,-1,sizeof p);
    cin >> n >> k;
    dfs(n,1);
}