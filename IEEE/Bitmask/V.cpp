#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
bool pow2(int x)
{
    return x & (x - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;  cin >> n;
    set<int> s;
    int d;
    for (int i = 0;i < n; i ++)
    {
        cin >> d;
        s.insert(d);
    }
    int ans = 1;
    int l,h;
    bool found = false;
    bool is = false;
    for (auto it = s.begin();it != s.end();it ++)
    {
        int diff = 0;
        
        int exp = 31;
        while (diff < exp && !is)
        {
            if (s.count(*it + (1<<diff)))
            {   
                ans = 2;
                l = *it;
                h = l + (1<<diff);
                if (s.count(*it + 2 * (1<<diff)))
                {
                    found = true;
                    is = true;
                    ans = 3;
                    cout << ans <<'\n';
                    cout << *it << " " << *it + (1<<diff) << " " << *it + 2 * (1<<diff);
                    break;
                }
            }
            diff ++; 
        }
        
    }
    if (ans == 2 && !found)
    {
        cout << ans <<'\n';
        cout << l << ' ' << h;
    }
    else if (!found){
        cout << 1 << '\n' << *s.begin();
    }
    return 0;
}