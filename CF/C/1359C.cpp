#include<bits/stdc++.h>
using namespace std;
double h,c,t;
int testCases;
double f(double m)
{
    return (m * h + (m - 1) * c) / (2 * m - 1);
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> testCases;
    
    while (testCases --)
    {
        cin >> h >> c >> t;
        
        if (h == t) cout << "1\n";
        
        else if (h + c >= 2 * t)    cout << "2\n";

        else 
        {
            int low = 1,high = 1e8,it = 0;
            while (it ++ < 30)
            {
                int mid = low + (high - low) / 2;
                if (f(mid) <= t)    high = mid;
                else low = mid;
            }
            double d1 = f(low) - t;
            double d2 = t - f(high);
            
            cout << 2 * (d1 > d2 ? high : low) - 1<< '\n';
        }
    }

    return 0;
}