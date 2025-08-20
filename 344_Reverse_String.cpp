#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
    int l = s.size();
    for (int i=l-1; i>=0; i--){
        s.push_back(s[i]);
    }
    for (int i=0; i<l; i++){
        s.erase(s.begin());
    }
}

// using inbuilt function
void reverseString(vector<char>& s){
    reverse(s.begin(), s.end());
}