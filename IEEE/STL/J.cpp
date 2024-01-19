#include<bits/stdc++.h>
using namespace std;
#define ppi pair<pair<int,int>,int>
const int maxn = 1e5 + 1;
int l,c,n;
int p,x,a,b;
//Arreglo para conteo de frecuencias
int freq[maxn];
//Multiset para guardar freq[c] y modificar
//Manejo rapido del conteo de un color
multiset<int> frequencies;
//set de intervalos(L,R,C)
set<ppi> I;
int sum (int a,int b) {
    return (a % l + b % l) % l;
}
int mul(long long a,long long b) {
    return (a % l * b % l) % l;
}
bool intersect(int a,int b,int c,int d) {
    return min(b,d) >= max(a,c);
}
void update_frequency(int val,int c) {
    frequencies.erase(frequencies.find(freq[c]));
    freq[c] += val;
    frequencies.emplace(freq[c]);
}
void update(int L,int R,int X) {
    auto it = I.lower_bound(make_pair(make_pair(L,R),-1));
    if (it != I.begin())    it --;
    vector<ppi> intervals_with_intersection;
    while (it != I.end() && R >= it->first.first) {
        if (intersect(L,R,it->first.first,it->first.second)) intervals_with_intersection.emplace_back(*it);
        it ++;
    }
    for (auto e : intervals_with_intersection) {
        update_frequency(-(e.first.second - e.first.first + 1),e.second);
        I.erase(e);
        if (e.first.first < L) {
            I.insert(make_pair(make_pair(e.first.first,L - 1),e.second));
            update_frequency((L - e.first.first),e.second);
        }
        if (R < e.first.second) {
            I.insert(make_pair(make_pair(R + 1,e.first.second),e.second));
            update_frequency((e.first.second - R),e.second);
        }
    }
    I.insert(make_pair(make_pair(L,R),X));
    update_frequency(R - L + 1,X);
}
int main () {
    cin >> l >> c >> n;
    freq[1] = l;
    for (int i = 1; i <= c; i ++) frequencies.emplace(freq[i]);
    I.insert(make_pair(make_pair(0,l - 1),1));
    for (int i = 0; i < n; i ++) {
        cin >> p >> x >> a >> b;
        int s = freq[p];
        int L = sum(a,mul(s,s));
        int R = sum(a,mul(sum(s,b),sum(s,b)));
        
        if (L > R)  swap(L,R);
        update(L,R,x);
    }
    cout << *frequencies.rbegin();
    return 0;
}