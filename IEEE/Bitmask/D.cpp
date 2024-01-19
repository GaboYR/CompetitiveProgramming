#include<bits/stdc++.h>
using namespace std;
unsigned long long arr[10];
unsigned long long mask = 0;
int op, i;
void op0(){
    if (mask&(1ull<<i))  cout << "0\n";
    else cout << "1\n";
}
void op1() {
    for (int j = 0; j < 64; j ++) {
        if (arr[i]&(1ull<<j)) {
            mask |= (1ll<<j);
        }
    }
}
void op2() {
    // unsigned long long p = ~arr[i];
    // mask&=(p);
    for (int j = 0; j < 64; j ++) {
        if (arr[i]&(1ull<<j)){
            mask&=~(1ull<<j);
        }
    }
}
void op3() {
    for (int j = 0; j < 64; j ++) {
        if (arr[i]&(1ull<<j)){
            mask^=(1ull<<j);
        }
    }
    //mask^=(arr[i]);
}
void op4() {
    // unsigned long long p = mask&arr[i]; 
    // if (p == arr[i])    cout << "1\n";
    // else cout << "0\n";
    bool is = true;
    for (int j = 0; j < 64 && is; j ++) {
        auto p = arr[i]&(1ull<<j);
        auto q = mask&(1ull<<j);
        if (p != q) {
            is = false;
        }
    }
    if (is) cout << "1\n";
    else cout << "0\n";
}
void op5() {
    // unsigned long long p = mask&arr[i];
    // if (p)  cout << "1\n";
    // else cout << "0\n";
    int res = 0;
    for (int j = 0; j < 64; j ++) {
        auto p = arr[i]&(1ull<<j);
        auto q = mask&(1ull<<j);
        if (p == q) res ++;
    }
    if (res)    cout << "1\n";
    else cout << "0\n";
}
void op6() {
    // unsigned long long p = mask&arr[i];
    // if (p)  cout << "0\n";
    // else cout << "1\n";
    bool is = true;
    for (int j = 0; j < 64; j ++) {
        auto p = arr[i]&(1ull<<j);
        auto q = mask&(1ull<<j);
        if ((p & q) != 0)   is = false;
    }
    if (is) cout << "1\n";
    else cout << "0\n";
}
void op7() {
    int res = 0;
    for (int j = 0; j < 64; j ++) {
        if ((arr[i]&(1ull<<j)) != 0 && (mask&(1ll<<j)))   res ++;
    }
    cout << res << "\n";
}
void op8() {
    unsigned long long p = 0;
    for (int j = 0; j < 64; j ++) {
        if (arr[i]&(1ll<<j))    p += (1ull<<j)&mask;
    }
    cout << p << "\n";
}

int main () {
    int n;  cin >> n;
    for (int j = 0;j < n; j ++) {
        int k;  cin >> k;
        while (k --) {
            int d;  cin >> d;
            arr[j]|=(1ll<<d);
        }
    }
    int q;  cin >> q;
    while (q --) {
        cin >> op >> i;
        if (op == 0)         op0();
        else if (op == 1)    op1();
        else if (op == 2)    op2();
        else if (op == 3)    op3();
        else if (op == 4)    op4();
        else if (op == 5)    op5();
        else if (op == 6)    op6();
        else if (op == 7)    op7();
        else if (op == 8)    op8();
        //cout << "mask : " << mask << "\n";
    }
    return 0;
}