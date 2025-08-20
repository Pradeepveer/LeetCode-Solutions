#include<bits/stdc++.h>
 
using namespace std;


string convert(string s, int numRows){
    string ans;
    vector<vector<char>> rows(numRows);
    int direction = 1;
    int k = 0;
    for (char c : s){
        rows[k].push_back(c);
        k += direction;
        if (k==0 || k==numRows-1){
            direction *= -1;
        }
    }
    
    for (const vector<char>& row : rows){
        for (const char c : row){
            ans += c;
        }
    }
    return ans;
}   

int main(){
    cout<<convert("PAYPALISHIRING", 3)<<endl;
    cout<<convert("PAYPALISHIRING", 4)<<endl;
}
