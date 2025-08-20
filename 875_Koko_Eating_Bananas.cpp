#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double time(vector<int>& piles, int speed){
        double t = 0;
        for (int i=0; i<piles.size(); i++){
            t += ceil((double)piles[i] / (double)speed);
        }
        return t;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxpile = 0;
        for (int i=0; i<piles.size(); i++){
            if (piles[i] > maxpile) maxpile = piles[i];
        }        

        int l = 1, r = maxpile;

        while (l <= r){
            int mid = (l+r) / 2;
            double t = time(piles, mid); 
            if (t <= h) r = mid - 1;
            else l = mid + 1;
        }

        return l;
    }
};