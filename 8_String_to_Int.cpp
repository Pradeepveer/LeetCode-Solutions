#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        
        int i = 0;
        int sign = 1;
        while (isspace(s[i])) i++;
        if (s[i] == '-'){
            sign = -1;
            i++;
        }
        else if (s[i] == '+') i++;

        while (isdigit(s[i])){
            ans = ans*10 + (s[i] - '0');
            if (ans >= INT_MAX){
                if (sign == 1) return INT_MAX;
                if (sign == -1 && ans*-1 <= INT_MIN) return INT_MIN;
            }
            i++;
        }
        return (int)(ans * -1);
    }
};