#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int maxi = numBottles;
        int empty = numBottles;
        while(empty >= numExchange){
            maxi++;
            empty = empty + 1 - numExchange;
            numExchange++;
        }
        return maxi;
    }
};