#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int top = 0;
        int bottom = n-1;
        int l = 0;
        int h = m-1;

        if (target < matrix[0][0] || target > matrix[n-1][m-1]) return false;

        while (top <= bottom){
            int mid = (top + bottom)/2;
            if (matrix[mid][0] > target) bottom = mid - 1;
            else top = mid + 1;
        }

        int r = bottom;
        while (l <= h){
            int mid = (l+h)/2;
            if (matrix[r][mid] == target) return true;
            else if (matrix[r][mid] < target){
                l = mid + 1;
            }
            else{   // target < row[mid]
                h = mid - 1;
            }
        }

    return false;
    }
};  