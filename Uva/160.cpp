#include<bits/stdc++.h>
using namespace std;
vector<bool> isPrime;
vector<int> primes;
int table[105][105];
void criba(int n) {
    isPrime = vector<bool>(n, true);
    primes = vector<int>();
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int h=2; h*i<n; ++h) isPrime[i*h] = 0;
        }
    }
}
map<int,int> desc(int n)
{
    map<int,int> mp;
    int it = 3;
    while (n != 1)
    {
        while (n % 2 == 0)
        {
            mp[2] ++;
            n /= 2;
        }
        while (n % it == 0)
        {
            mp[it] ++;
            n /= it;
        }
        it += 2;
    }
    return mp;
}

void init()
{
    criba(100);
    for (int i = 2; i < 101; i ++) 
    {
        auto f = desc(i);
        for (auto ff: f)
        {
            table[i][ff.first] += ff.second;
        }
    }
    for (int i = 3;i < 101; i ++)
    {
        for (auto e : primes)
        {
            table[i][e] += table[i - 1][e];
        }
    }
}
void printFactorialPrimes(int n)
{
    if (n < 10) cout << "  ";
    if (n >= 10 && n < 100)  cout << ' ';
    cout << n << "! =";
    int cont = 0;
    for (auto e : primes)
    {
        if (table[n][e])
        {
            cont ++;
            if (cont > 15) 
            {
                cout << "\n      ";
                cont -= 15;
            }
            if (table[n][e] < 10)    cout << "  ";
            else cout << ' ';
            cout << table[n][e];
            
        }    
    }
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    int n;
    
    while (cin >> n,n)
    {
        printFactorialPrimes(n);
    }
    return 0;
}