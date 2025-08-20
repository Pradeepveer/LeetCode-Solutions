
#include<bits/stdc++.h>
using namespace std;


// rotating outer squares and moving inside
void rotate(vector<vector<int>>& M) {
    int n = M.size(), depth = n / 2;
    for (int i = 0; i < depth; i++) {
        int len = n - 2 * i - 1, opp = n - 1 - i;
        for (int j = 0; j < len; j++) {
            int temp = M[i][i+j];
            M[i][i+j] = M[opp-j][i];
            M[opp-j][i] = M[opp][opp-j];
            M[opp][opp-j] = M[i+j][opp];
            M[i+j][opp] = temp;
        }
    }
}

// 1. take transpose
// 2. reverse rows
void rotate(vector<vector<int>>& matrix) {
    int row=matrix.size();
    int col=matrix[0].size();
    // vector<vector<int>>traspose;
    for(int i=0;i<row;i++){
        for(int j=i;j<col;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    //reverse row wise
    for(int i=0;i<row;i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
    
}