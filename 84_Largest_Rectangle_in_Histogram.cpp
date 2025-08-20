#include<bits/stdc++.h>
using namespace std;


int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxi = 0;

    for (int i=0; i<heights.size(); i++){
        while (!st.empty() && heights[st.top()] > heights[i]){
            int nseindx = i;
            int curr = heights[st.top()];
            st.pop();
            int pseindx = st.empty() ? -1 : st.top();
            maxi = max(maxi, curr * (nseindx - pseindx - 1));            
        }
        st.push(i);
    }

    while(!st.empty()){
        int nseindx = heights.size();
        int curr = heights[st.top()];
        st.pop();
        int pseindx = st.empty() ? -1 : st.top();
        maxi = max(maxi, curr * (nseindx - pseindx - 1));
    }

    return maxi;
}   


/*
another method
find nseindx and pseindx seperatly and keep in vectors<int> 
for each element of heights area = curr * (nseindx - pseindx -1)
maxi = max(maxi, area);
*/