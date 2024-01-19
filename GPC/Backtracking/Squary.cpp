#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[30];
void print(){
    for (int i = 0; i < k; i ++) {
        cout << a[i] << " ";
    }
}
void dfs(int n,int count) {
    if (n < 0)  return;
    if (n == 0 && count == k){
        print();       
    }
    if (count > k)  return;
    for (int num = 1; num * num < n;num ++) {
        a[count] = num;
        dfs(n - num * num,count + 1);
        a[count] = 0;
    }
}
void solve() {
    dfs(n,0);
}
int main() {
    cin >> n >> k;
    solve();
    return 0;
}