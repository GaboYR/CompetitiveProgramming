#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int arr[N];
int n,l,r;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt;  cin >> tt;
    while (tt --)
    {
        cin >> n >> l >> r;
        for (int i = 0; i < n; i ++)    cin >> arr[i];
        sort(arr,arr + n);
        long long sum = 0;
        for (int i = 0; i < n;i ++) 
        {
            auto lw = lower_bound(arr + i + 1,arr + n,l - arr[i]);
            auto up = lower_bound(arr + i + 1,arr + n,r - arr[i] + 1);
            sum += up - lw;
        }
        cout << sum << '\n';
    }
    return 0;
}