#include<bits/stdc++.h>
using namespace std;


int maxScore(vector<int>& cardPoints, int k) {
    int maxsum = 0;
    int lsum = 0, rsum = 0;
    int n = cardPoints.size();

    for (int i=0; i<k; i++){
        lsum += cardPoints[i];
    }
    maxsum = lsum;
    int rindx = cardPoints.size() - 1;
    for (int i=k-1; i>=0; i--){
        lsum -= cardPoints[i];
        rsum += cardPoints[rindx];
        maxsum = max(maxsum, lsum + rsum);
        rindx--;
    }
    return maxsum;
}