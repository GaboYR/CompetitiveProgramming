#include<bits/stdc++.h>
using namespace std;
const int maxn = 1004;
pair<int,int> dp[maxn][maxn];
int dx[] ={-1,0};
int dy[] = {0,-1};
int n;
string res;
bool check(int x,int y) {
    return x >= 0 && y >= 0;
}
void pp(int x,int y) {
    cout << "("<< dp[x][y].first << " " << dp[x][y].second << ")";
}
pair<int,int> min(pair<int,int> a,pair<int,int> b) {
    int x = a.first;
    int y = a.second;
    int z = b.first;
    int w = b.second;
    int tmp = min(x,min(y,min(z,w)));
    bool p1,p2,p3,p4;
    p1 = tmp == x;
    p2 = tmp == y;
    p3 = tmp == z;
    p4 = tmp == w;
    if (p1 || p2) {
        if (p3 || p4) {
            if (p1 && p2) {
                return a;
            }
            else if (p1) {
                if (p3 && p4)   return b;
                else if (p3) {
                    if (y < w)  return a;
                    return b;
                }
                else if (p4) {
                    if (y < z)  return a;
                    return b;
                }
            }
            else if (p2) {
                if (p3 && p4)   return b;
                else if (p3) {
                    if (x < w)  return a;
                    return b;
                }
                else if (p4) {
                    if (x < z)  return a;
                    return b;
                }
            }
        }
        else {
            return a;
        }
    }
    return b;
}
void print_path(){
    int x = n - 1,y = n - 1;
    int cnt = 0;
    //Buscando el camino de atras hacia adelante 
    while ((x || y) && cnt < 2 * n - 2) {
        //cout << "Origen:\n";
        //cout << x << " " << y << " -> ";
        //cout << "("<< dp[x][y].first << " " << dp[x][y].second << ")";
        //cout << "\nPosibles caminos: ";
        if (x == 0) {
            res += "R";
            //pp(x,y);
            y --;
        }
        else if (y == 0) {
            res += "D";
            //pp (x,y);
            x --;
        }
        else {
            int nx1,ny1,nx2,ny2;
            nx1 = x,    ny1 = y - 1;
            nx2 = x - 1,ny2 = y;
            //pp(nx1,ny1);
            //pp(nx2,ny2);
            auto m = min(dp[nx1][ny1],dp[nx2][ny2]);
            //cout << "\nMinimo: " <<  m.first << " " << m.second << '\n';
            if (m == dp[nx1][ny1]) {
                x = nx1,y = ny1;
                res += "R";
            }
            else {
                x = nx2,y = ny2;
                res += "D";
            }
            //cout << "(" <<  x << " " << y << ")\n";
        }
        //std::cout << x << " " << y;
        //cout << '\n';
    cnt ++;
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            int d;  cin >> d;
            if (d != 0) {
                while (d % 2 == 0) {
                    dp[i][j].first ++;
                    d /= 2;
                }
                while(d % 5 == 0) {
                    dp[i][j].second ++;
                    d /= 5;
                }
            }
            
        }
    }
    for (int i = 0; i < n; i ++) {
        
        for (int j = 0; j < n; j ++) {
            if (i == 0 && j > 0) {
                dp[i][j].first += dp[i][j - 1].first;
                dp[i][j].second += dp[i][j - 1].second;
            }
            else if (j == 0 && i > 0) {
                dp[i][j].first += dp[i - 1][j].first;
                dp[i][j].second += dp[i - 1][j].second;
            }
            else if (i && j){
                int af = dp[i][j].first + dp[i - 1][j].first;
                int as = dp[i][j].second + dp[i - 1][j].second;
                int bf = dp[i][j].first + dp[i][j - 1].first;
                int bs = dp[i][j].second + dp[i][j - 1].second;
                
                dp[i][j] = min(make_pair(af,as),make_pair(bf,bs));
                // std::cout << "("<< af << " "<< as << ")\t";
                // std::cout << "("<< bf << " "<< bs << ")\n";
            }
        }
    }
    // for (int i = 0; i < n; i ++) {
    //     for (int j = 0; j < n; j ++) {
    //         std::cout << "(" << dp[i][j].first << " " << dp[i][j].second << ") ";
    //     }
    //     std::cout << "\n";
    // }
    print_path();
    
    std::cout << min(dp[n - 1][n - 1].first,dp[n - 1][n - 1].second) << '\n';
    std::reverse(res.begin(),res.end());
    std::cout << res << '\n';
    
}