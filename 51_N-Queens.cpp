#include<bits/stdc++.h>
using namespace std;


void check(vector<string>& board, vector<vector<string>>& ans, vector<int>& leftrow, vector<int>& upperdiag, vector<int>& lowerdiag, int n, int col){
    
    if (col == n){
        ans.push_back(board);
        return;
    }

    for (int row=0; row<n; row++){
        if (leftrow[row] == 0 && upperdiag[n-1+col-row] == 0 && lowerdiag[row+col] == 0){
            leftrow[row] = 1;
            upperdiag[n-1+col-row] = 1;
            lowerdiag[row + col] = 1;
            board[row][col] = 'Q';

            check(board, ans, leftrow, upperdiag, lowerdiag, n, col+1);

            board[row][col] = '.';
            leftrow[row] = 0;
            upperdiag[n-1+col-row] = 0;
            lowerdiag[row + col] = 0;
        }
    }
}


vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board;
    string s(n, '.');

    vector<int> leftrow(n, 0);
    vector<int> upperdiag(2*n-1, 0);
    vector<int> lowerdiag(2*n-1, 0);

    for(int i=0; i<n; i++){
        board.push_back(s);
    }

    check(board, ans, leftrow, upperdiag, lowerdiag, n, 0);
    return ans;
}