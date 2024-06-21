#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin >> tt;
    vector<int> v(10);
    cout << "Lumberjacks:\n";
    while (tt--)
    {
        for (int i = 0; i < 10; i++)
        {
            cin >> v[i];
        }
        if (is_sorted(v.begin(), v.end()))
        {
            cout << "Ordered";
        }
        else
        {
            reverse(v.begin(), v.end());
            if (is_sorted(v.begin(), v.end()))
            {
                cout << "Ordered";
            }
            else
                cout << "Unordered";
        }
        cout << "\n";
    }

    return 0;
}