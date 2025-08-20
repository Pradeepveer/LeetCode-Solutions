#include<bits/stdc++.h>
using namespace std;


bool search(int indx, int row, int col, int totrows, int totcols, vector<vector<char>>& board, string word){
    if (indx == word.size()) return true;

    if (row == -1 || col == -1 || row == totrows || col == totcols || board[row][col] != word[indx]) return false;

    char c = board[row][col];
    board[row][col] = '-';

    bool top = search(indx+1, row-1, col, totrows, totcols, board, word);
    bool right = search(indx+1, row, col+1, totrows, totcols, board, word);
    bool bottom = search(indx+1, row+1, col, totrows, totcols, board, word);
    bool left = search(indx+1, row, col-1, totrows, totcols, board, word);
    
    board[row][col] = c;  

    return top || right || bottom || left;
}

bool exist(vector<vector<char>>& board, string word) {
    int totrows = board.size();
    int totcols = board[0].size();
    
    for (int i=0; i<totrows; i++){
        for (int j=0; j<totcols; j++){
            if (board[i][j] == word[0]){
                bool found = search(0, i, j, totrows, totcols, board, word);
                if (found) return true;
            }
        }
    }
    return false;
}
