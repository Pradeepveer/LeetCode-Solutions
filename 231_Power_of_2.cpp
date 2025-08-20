#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n < 1) return false;

    int logval = log2(n);
    return (n>0) && (pow(2, logval) == n);
}