#include<bits/stdc++.h>
using namespace std;
bitset<64> mask[10];
bitset<64> val;
int n,op,i;
void op0() {
    if (val[i] == 1) cout << "1\n";
    else cout << "0\n";
}
void op1() {
    for (int j = 0; j < 64; j ++) {
        if (mask[i][j] == 1)    val[j] = 1;
    }
}
void op2() {
    for (int j = 0; j < 64; j ++) {
        if (mask[i][j] == 1)    val[j] = 0; 
    }
}
void op3() {
    for (int j = 0; j < 64; j ++) {
        if (mask[i][j] == 1)    val[j] = 1 - val[j];
    }
}
void op4(){ 
    bool is = true;
    for (int j = 0; j < 64; j ++) {
        if (mask[i][j] == 1){
            if (val[j] == 0)    is = false;
        }
    }
    if (is) cout << "1\n";
    else cout << "0\n";
}
void op5() {
    bool is = false;
    for (int j = 0; j < 64; j ++) {
        if (mask[i][j] == 1) {
            if (val[j] == 1) {
                is = true;
            }
        }
    }
    if (is) cout << "1\n";
    else cout << "0\n";
}
void op6() {
    bool is = true;
    for (int j = 0; j < 64; j ++) {
        if (mask[i][j] == 1) {
            if (val[j] == 1)    is = false;
        }
    }
    if (is) cout << "1\n";
    else cout << "0\n";
}
void op7() {
    int res = 0;
    for (int j = 0; j < 64; j ++) {
        if (mask[i][j] == 1){
            if (val[j] == 1)    res ++;
        }
    }
    cout << res << "\n";
}
void op8() {
    unsigned long long res = 0,b = 1;
    for (int j = 0; j < 64; j ++) {
        //cout << val[j];
        if (mask[i][j] == 1) {
            res += val[j] * b;
        }
        b *= 2;
    }
    //cout << "\nRes: " << res << "\n";
    cout << res << "\n";
    //cout << "\n" <<res <<"\n";
}
int main () {
    int n;  cin >> n;
    for (int j = 0; j < n; j ++) {
        int k;  cin >> k;
        while (k --) {
            int d;  cin >> d;
            mask[j][d] = 1;
        }
    }
    int q;  cin >> q;
    while (q --) {
        cin >> op >> i;
        if      (op == 0)   op0();
        else if (op == 1)   op1();
        else if (op == 2)   op2();
        else if (op == 3)   op3();
        else if (op == 4)   op4();
        else if (op == 5)   op5();
        else if (op == 6)   op6();
        else if (op == 7)   op7();
        else if (op == 8)   op8();
        //  cout << "val = ";
        //  op8();
        //  cout << "------\n";
    }
    return 0;
}