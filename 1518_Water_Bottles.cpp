#include<bits/stdc++.h>
using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int ans = numBottles;
    int empty = numBottles;
 
    while(empty >= numExchange){
        ans += empty / numExchange;
        empty = (empty % numExchange) + (empty / numExchange);
    }

    return ans;
}