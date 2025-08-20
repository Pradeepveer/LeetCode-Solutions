#include<bits/stdc++.h>
using namespace std;


int aggresiveCows(vector<int> stalls, int cows){
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int l = stalls[0];
    int h = stalls[n-1] - stalls[0];

    while(l <= h){
        int m = (l+h)/2;
        if (canweplace(stalls, cows, m)) l = m + 1;
        else h = m - 1;
    }
    return h;
}

bool canweplace(vector<int> stalls, int cows, int dist){
    int cnt = 1;
    int last = stalls[0];
    for (int i=0; i<stalls.size(); i++){
        if (stalls[i] - last >= dist){
            cnt++;
            last = stalls[i];
        }
    }
    if (cnt >= cows) return true;
    return false;
}

