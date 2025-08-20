#include<bits/stdc++.h>
using namespace std;

// 11ms
void setZeroes(vector<vector<int>>& matrix) {
    vector<int> r;
    vector<int> c;
    int rows = matrix.size();
    int cols = matrix[0].size();        

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            if (matrix[i][j]==0){
                if ((count(r.begin(), r.end(), i) == 0)){
                    r.push_back(i);
                }
                if ((count(c.begin(), c.end(), j) == 0)){
                    c.push_back(j);
                }
            }
        }
    }

    for (int i=0; i<r.size(); i++){
        for (int j=0; j<cols; j++){
            matrix[r[i]][j] = 0;
        }
    }

    for (int j=0; j<c.size(); j++){
        for (int i=0; i<rows; i++){
            matrix[i][c[j]] = 0;
        }
    }
    return;
}

// 0ms
void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int> > v;

        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j] == 0) {
                    v.push_back(make_pair(i,j));
                }
            }
        }

        for(int i=0;i<v.size(); i++) {
            int row=v[i].first;
            int col=v[i].second;

            for(int j=0;j<matrix[0].size();j++) {
                matrix[row][j] = 0;
            }

            for(int j=0;j<matrix.size();j++) {
                matrix[j][col] =0;
            }
        }
    }