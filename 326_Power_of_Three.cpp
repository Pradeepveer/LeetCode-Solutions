#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int logval = log2(n)/log2(3);
        return n == pow(3, logval);
    }

    bool isPowerOfThree(int n){
        if (n <= 0) return false;
        while(n % 3 == 0){
            n /= 3;
        }
        return n == 1;
    }
};