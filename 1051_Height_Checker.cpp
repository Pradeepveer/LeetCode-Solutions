#include<bits/stdc++.h>
using namespace std;

int heightChecker(vector<int>& heights) {
    vector<int> h_sorted = heights;
    sort(h_sorted.begin(), h_sorted.end());
    int a = 0;
    for (int i=0; i<h_sorted.size(); i++){
        if (heights[i] != h_sorted[i]){
            a++;
        }
    }
    return a;
}