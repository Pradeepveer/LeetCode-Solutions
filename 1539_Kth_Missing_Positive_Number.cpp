#include<bits/stdc++.h>
using namespace std;


int findKthPositive(vector<int>& arr, int k) {
    int l = 0;
    int h = arr.size() - 1;
    int missing = 0;
    while (l <= h){
        int m = (l+h)/2;
        missing = arr[m] - m - 1; 
        if (missing < k) l = m + 1;
        else h = m - 1;
    }        
    return k + h + 1;
}
