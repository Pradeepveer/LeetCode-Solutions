#include<bits/stdc++.h>
using namespace std;

bool checkpalindrome(string s){
    int l = s.size();
    for (int i=0; i<(l/2); i++){
        if (s[i] != s[l-i-1]){return false;}
    }      
    return true;  
}

// timelimit exceed
string longestPalindrome(string s) {
    int len = s.size();
    if (len == 1 || len == 0){return s;}
    int start = 0;
    int maxlen = 0;
    char c = s[0];
    string ans = "";
    ans += c;

    for (; start<len; start++){
        int iter = start+1;
        for(; iter<len; iter++){
            if (s[iter] == s[start]){
                int l = iter - start + 1;
                string substr = s.substr(start, l);
                bool palindrome = checkpalindrome(substr);
                if (palindrome == true && l>maxlen){
                    ans = substr;
                    maxlen = l;
                }
            }
        }
    }     
    return ans;   
}



bool checkpalindrome(char* st, char* end){
    int l = end - st + 1;
    for (int i=0; i<(l/2); i++){
        if (*st != *end){return false;}
        else {
            st++; 
            end--;
        }
    }      
    return true;  
}

// 118ms
string longestPalindrome(string s) {
    int len = s.size();
    if (len <= 1){return s;}
    int start = 0;
    int maxlen = 0;
    char c = s[0];
    string ans = "";
    ans += c;

    for (; start<len; start++){
        int iter = len - 1;
        for(; iter>=start; iter--){
            if (s[iter] == s[start]){
                int l = iter - start + 1;
                if (l > maxlen){
                    bool palindrome = checkpalindrome(&s[start], &s[iter]);
                    if (palindrome == true){
                        maxlen = l;
                        ans = s.substr(start, l);
                    }
                }
            }
        }
    }     
    return ans;   
}

