#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void f(vector<vector<string>>& phone, vector<string>& ans, string temp, string digits, int ind){
        if (temp.size() == digits.size()){
            ans.push_back(temp);
            return;
        }
        if (ind == digits.size()) return;
        
        vector<string> str = phone[digits[ind]-'2'];
        for (int i=0; i<str.size(); i++){
            temp += str[i];
            f(phone, ans, temp, digits, ind+1);
            temp.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        int k = digits.size();
        vector<vector<string>> phone {
            {"a", "b", "c"}, {"d", "e", "f"},
            {"g", "h", "i"}, {"j", "k", "l"},
            {"m", "n", "o"}, {"p", "q", "r", "s"},
            {"t", "u", "v"}, {"w", "x", "y", "z"}
        };

        vector<string> ans;
        string temp = "";
        f(phone, ans, temp, digits, 0);
        if (digits.size() == 0) return {};
        return ans;
    }
};
