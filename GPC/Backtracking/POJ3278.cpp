#include<iostream>
using namespace std;
int back(int n,int k) {
    if (n >= k)     return n - k;
    if (n == 0)     return 1 + back(n + 1,k);
    if (k & 1)      return 1 + min(back(n,k + 1),back(n,k - 1));
    else            return min(k - n,1 + back(n,k/2));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;  cin >> n;
    int k;  cin >> k;
    cout << back(n,k) << "\n";
    return 0;
}