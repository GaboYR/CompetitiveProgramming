/*
    https://codeforces.com/group/OyefIGO3t4/contest/447261/problem/B
    https://codeforces.com/problemset/problem/459/D
*/
#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
map<int,int> p,q;
long long dc(vector<int> &l,vector<int> &r)
{
    long long ans = 0;
    int i = 0,j = 0;
    while (i < sz(l) && j < sz(r))
    {
        if (r[j] < l[i])    j ++;
        else 
        {
            i ++;
            ans += j;
        }
    }
	while (i ++ < sz(l))   ans += j;
	return ans;
}
long long merge(vector<int> &a,vector<int> &b)
{
    if (sz(a) <= 1)  return 0;
    int mid = sz(a) / 2;

    vector<int> la(a.begin(),a.begin() + mid);
    vector<int> ra(a.begin() + mid,a.end());
    vector<int> lb(b.begin(),b.begin() + mid);
    vector<int> rb(b.begin() + mid,b.end());

    long long res = merge(la,lb) + merge(ra,rb);

    sort(la.begin(),la.end());
    sort(rb.begin(),rb.end());

    return res + dc(la,rb);
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;  cin >> n;
    vector<int> a(n),contL(n),contR(n);
    
    for (int i = 0; i < n; i ++)   cin >> a[i];
    
    for (int i = 0; i < n; i ++)
    {
        contL[i] = ++ p[a[i]];
        contR[n - i - 1] = ++ q[a[n - i - 1]];
    }
    cout << merge(contL,contR) << '\n';
    return 0;
}
