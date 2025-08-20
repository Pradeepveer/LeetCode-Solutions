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

int maximalRectangle(vector<vector<char>>& matrix) {
    int cols = matrix[0].size();
    int rows = matrix.size();
    vector<int> currhist(cols, 0);
    int maxi = 0;

    vector<vector<int>> prefixsum;

    for (int j=0; j<cols; j++){
        int sum = 0;
        for (int i=0; i<rows; i++){
            sum += matrix[i][j];
            if (matrix[i][j] == 0) sum = 0;
            prefixsum[i][j] = sum;
        }
    }

    for (int i=0; i<rows; i++){
        maxi = max(maxi, largestRectangleArea(prefixsum[i]));
    }

    return maxi;
}   