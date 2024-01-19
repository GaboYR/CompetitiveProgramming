#include<iostream>
using namespace std;
int main() {
        long long a,b;
        while (cin >> a >> b,a != 0 || b != 0) {
            int carry = 0,c = 0;
            int r1,r2;
            while (a || b) {
                r1 = a % 10;
                r2 = b % 10;
                if (r1 + r2 + c > 9){
                    carry ++;
                    c = 1;
                }
                else c = 0;
                a /= 10;
                b /= 10;
            }
            if (carry == 0) cout << "No";
            if (carry != 0) cout << carry ;
            cout << " carry operation";
            cout << (carry == 1 || carry == 0?"":"s");
            cout << ".\n";
    }
    
}