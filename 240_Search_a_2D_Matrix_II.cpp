#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // binary search each row
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if (target < matrix[0][0] || target > matrix[n-1][m-1]) return false;

        for (int i=0; i<n; i++){
            int l = 0;
            int h = m-1;
            while (l<=h){
                int mid = (l+h)/2;
                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] > target) h = mid -1;
                else l = mid + 1;
            }
        }

        return false;
    }

    // optimal
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if (target < matrix[0][0] || target > matrix[n-1][m-1]) return false;

        int row = 0;
        int col = m-1;

        while (row < n && col >= 0){
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row++;
            else col--;
        }

        return false;
    }
};