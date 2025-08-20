#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int top = 0;
    int bottom = rows - 1 ;
    int left = 0;
    int right = cols - 1;

    vector<int> ans;
    while (top <= bottom && left <= right){
        for (int i=left; i <= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        for (int i=top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top<=bottom){
            for (int i=right; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right){
            for (int i=bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}


/*
00 01 02 03 04 05 
10 11 12 13 14 15
20 21 22 23 24 25
30 31 32 33 34 35
40 41 42 43 44 45
50 51 52 53 54 mn


*/


