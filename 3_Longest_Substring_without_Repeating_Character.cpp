#include<bits/stdc++.h>
using namespace std;

// asdffgadfd agasdf safsd f
int lengthOfLongestSubstring(string s) {
    if (s.size() == 0){
        return 0;
    }
    int a = -1;
    vector<int> v(128, -1);
    int maxlen = 0;
    for (int i=0; i<s.size(); i++){
        a = max(a, v[s[i]]);
        maxlen = max(maxlen, i-a+1);
        v[s[i]] = i;
    }
    return maxlen;
}