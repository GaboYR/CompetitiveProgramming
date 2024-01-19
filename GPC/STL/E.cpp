#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int main () {

    int n;  cin >> n;
    vector<pair<int,int>> v(n);

    for (int i = 0; i < n; i ++)    cin >> v[i].first >> v[i].second;
    
    sort(v.begin(),v.begin() + n);

    int rooms = 0, curr_rooms = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for (int i = 0; i < n; i ++) {
        if (pq.empty()) {
            curr_rooms ++;
            pq.push(v[0].second);
            a[v[i].second] = curr_rooms;
        }
        else {
            if (a[rooms] < v[i].first) {
                rooms ++;
                pq.push(v[i].second);
                a[i] = rooms;
            }
            else {
                pq.push(v[i].second);
                a[rooms] = v[i].second;
            }
        }
        rooms = max(rooms,int(size(pq)));
    }
    cout << rooms;

}