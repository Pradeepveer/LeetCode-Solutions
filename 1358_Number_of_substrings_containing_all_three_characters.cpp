#include<bits/stdc++.h>
using namespace std;



int numberOfSubstrings(string s) {
    int cnt = 0;
    vector<int> lastseen(3,-1);
    for (int i=0; i<s.size(); i++){
        lastseen[s[i] - 'a'] = i;
        cnt += 1 + min(lastseen[0], min(lastseen[1], lastseen[2]));
    }
    return cnt;
}