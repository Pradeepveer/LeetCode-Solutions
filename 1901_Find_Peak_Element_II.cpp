#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // find max element in column : return row of maxelem
    int indxmax(vector<vector<int>>& mat, int mid, int n){
        int maxi = INT_MIN;
        int indx = -1;
        for (int i=0; i<n; i++){
            if (mat[i][mid] > maxi){
                maxi = mat[i][mid];
                indx = i;
            }
        }

        return indx;
    }    

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0;
        int high = m - 1;
        int row = 0;

        // if only 1 column 
        if (m == 1){
            row = indxmax(mat, 0, n);
            return {row, 0};
        }

        while (low <= high){
            int mid = (low + high) / 2;
            row = indxmax(mat, mid, n);
            
            if (mid == 0 && mat[row][mid] > mat[row][mid+1]){
                return {row, mid};
            }

            else if(mid == m-1 && mat[row][mid] > mat[row][mid-1]){
                return {row, mid};
            }

            else{
                if (mat[row][mid] > mat[row][mid+1] && mat[row][mid-1] < mat[row][mid]){
                    return {row, mid};
                }

                else if (mat[row][mid] < mat[row][mid+1]){
                    low = mid + 1;
                }

                else high = mid - 1;
            }
        }

        return {-1, -1};
    }
};