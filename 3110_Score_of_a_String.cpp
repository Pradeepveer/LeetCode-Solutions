#include<bits/stdc++.h>
using namespace std;

int scoreOfString(string s) {
    int ans = 0;
    for (int i=0; i<s.length() - 1; i++){
        int a = int(s[i]);
        int b = int(s[i+1]);

        if (a>b){
            ans += a-b;
        }
        else {ans += b-a;}
    }        
    return ans;
}