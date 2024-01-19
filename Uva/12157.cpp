#include<iostream>
using namespace std;
int costMile(int x){
   return 10 * ((x + 30)/30);
}
int costJuice(int x) {
    return  15 * ((x + 60)/60);
}
int main() {
    int tt; cin >> tt;
    for (int i = 1; i <= tt; i ++) {
        cout << "Case " << i << ": ";
        int n;  cin >> n;
        int mile = 0,juice = 0;
        while (n --) {
            int d;  cin >> d;
            mile += costMile(d);
            juice += costJuice(d);
        }
        if (mile > juice) {
            cout << "Juice " << juice;
        }
        else if (mile == juice) {
            cout << "Mile Juice " << mile;
        }
        else cout << "Mile " << mile;
        cout << "\n";
    }
}