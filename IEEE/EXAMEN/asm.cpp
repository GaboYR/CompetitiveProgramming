#include<bits/stdc++.h>
using namespace std;
int max_value(int a, int b, int c) {
  // Initialize variables.
  int v0 = a;
  int v1 = b;
  int v2 = c;
  int v3 = 1;
  // Calculate the maximum value.
  int v4 = v3 - 1;
  int v5 = v4 - 1;
  int v6 = v3;
  int v7 = v4;
  v7 -= v1;
  int v9 = v0;
  v9 += v0;
  int v10 = v4;
  int v11 = v4;
  int v12 = v3;
  while (v12 <= v2) {
    v11 += v1;
    v10 += v0;
    int v13 = v10;
    int v14 = v4;
    int v15 = v4;
    while (v13 <= v1) {
      v13 -= 1;
      v14 += v3;
      v15 += v3;
    }
    if (v13 > v4) {
      v13 -= v4;
    }
    int v17 = v4;
    int v18 = v3;
    while (v17 <= v6) {
      v17 += v13;
      v18 += v3;
      if (v18 <= v12) {
        continue;
      }
      if (v17 >= v4) {
        break;
      }
      v5 = v14;
      v6 = v12;
      v7 = v15;
      v8 = v10;
      v9 = v13;
    }
    v12 += v3;
  }
  return v6;
}