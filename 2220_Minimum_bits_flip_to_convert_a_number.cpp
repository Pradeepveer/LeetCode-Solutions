#include<bits/stdc++.h>
using namespace std;


int minBitFlips(int start, int goal) {
    int ans = start ^ goal;
    int cnt = 0;
    while(ans){
        cnt += (ans & 1);
        ans >>= 1;
    }        
    return cnt;
}