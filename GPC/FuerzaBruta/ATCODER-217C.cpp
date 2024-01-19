#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n;   cin >> n;
    ll a,b,c;
    bool solu = false;
    for(int i = 1; i <= 3500 && !solu; i++){
        for(int j = 1; j <= 3500 && !solu; j++){
            if(!solu){
                a = i,b = j;
                ll num = (n*a*b);
                ll den = (4*a*b - n*a - n*b);
                if(den != 0) c = num/den;
                if(n*(a * b + b * c + a * c) == 4 * a * b * c && c > 0){
                    solu = true;
                    cout << a << " " << b << " " << c << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}