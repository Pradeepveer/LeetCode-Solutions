#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int>& prices) {
    if (prices.size() < 2){return 0;}
    int min = prices[0];
    int profit = 0;

    for (int i=0; i<prices.size(); i++){
        profit = max(prices[i]-min, profit);
        if (prices[i] < min){
            min = prices[i];
        }
        profit = max(prices[i]-min, profit);

    }       
    return profit; 
}

int maxProfit(vector<int>& prices) {
    int n = prices.size() ;
    int mini = prices[0];
    int maxprofit = 0;

    for (int i=0; i<n; i++){
        int cost = prices[i] - mini;
        maxprofit = max(maxprofit, cost);
        mini = min(mini, prices[i]);
    }
    return maxprofit;
}