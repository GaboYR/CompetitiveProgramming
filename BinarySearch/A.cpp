#include<bits/stdc++.h>
using namespace std;
int x,y,p,q,len;
string s;
int xx = 0,yy = 0;
bool f(long long m)
{
    long long d = m / len;
    long long r = m % len;
    long long dx = xx * d;
    long long dy = yy * d;
    for (int i = 0; i < r; i ++)
    {
        if (s[i] == 'U')    dy ++;
        if (s[i] == 'D')    dy --;
        if (s[i] == 'L')    dx --;
        if (s[i] == 'R')    dx ++;
    }
    return abs(p - (x + dx)) + abs(q - (y + dy)) <= m;
}
int main ()
{
    cin >> x >> y >> p >> q >> len;
    cin >> s;
    for (int i = 0; i < len; i ++)
    {
        if (s[i] == 'U')    yy ++;
        if (s[i] == 'D')    yy --;
        if (s[i] == 'L')    xx --;
        if (s[i] == 'R')    xx ++;
    }
    long long low = 0, high = 4e18 + 5;
    while (high - low != 1)
    {
        //cout << low << ' ' << high << '\n';
        long long mid = low + (high - low) / 2;
        if (f(mid)) high = mid;
        else low = mid;
    }
    //cout << low << ' ' << high << '\n';
    cout << (f(high)?high : - 1) << '\n';
}
//Para lectura o salida de archivo
//g++ name.cpp  < in.txt(lee los datos desde el archivo in.txt)
//g++ name.cpp > out.txt(manda la salida a un nvo archivo out.txt)
