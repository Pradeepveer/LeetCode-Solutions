#include<bits/stdc++.h>
using namespace std;


int maxArea(vector<int>& height) {
    int l = height.size();
    int maxh = 0;
    int maxarea = 0;
    
    int st = 0;
    int end = l-1;

    while(st < end){
        maxh = min(height[st], height[end]);
        l = end - st;
        maxarea = max(maxarea, (end-st)*maxh);
        if (height[st] > maxh){end--;}
        else {st++;}
    }
    return maxarea;
}