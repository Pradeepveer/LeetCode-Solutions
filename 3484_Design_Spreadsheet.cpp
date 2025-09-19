#include<bits/stdc++.h>
using namespace std;



class Spreadsheet {
private:
    vector<vector<int>> sheet;

public:
    Spreadsheet(int rows) {
        sheet = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        cell.erase(cell.begin());
        int row = stoi(cell) - 1;
        sheet[row][col] = value;
        return;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        cell.erase(cell.begin());
        int row = stoi(cell) - 1;
        sheet[row][col] = 0;
        return;
    }
    
    int getValue(string formula) {
        string s1 = "";
        string s2 = "";
        
        int i = 1;
        while(formula[i] != '+'){
            s1 += formula[i];
            i++;
        }
        i++;
        while(i < formula.size()){
            s2 += formula[i];
            i++;
        }

        int val1 = 0, val2 = 0;
        if (isdigit(s1[0])){
            for (int i=0; i<s1.size(); i++){
                val1 = val1 * 10 + (s1[i] - '0');
            }
        }

        else{
            int c1 = s1[0] - 'A';
            s1.erase(s1.begin());
            int r1 = stoi(s1) - 1;
            val1 = sheet[r1][c1];
        }
        
        if (isdigit(s2[0])){
            for (int i=0; i<s2.size(); i++){
                val2 = val2 * 10 + (s2[i] - '0');
            }
        }
        else{
            int c2 = s2[0] - 'A';
            s2.erase(s2.begin());
            int r2 = stoi(s2) - 1;
            val2 = sheet[r2][c2];
        }

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */