#include<bits/stdc++.h>
using namespace std;


string minWindow(string s, string t) {
    int minlen = 1e5, l=0, r=0, cnt=0, startindx=-1;
    vector<int> v(256, 0);
    int n = s.size(), m = t.size();
    for (int i=0; i<m; i++) v[t[i]]++;

    while(r < n){
        if (v[s[r]] > 0) cnt++;
        v[s[r]]--;
        
        while(cnt == m){
            if (r-l+1 < minlen){
                startindx = l;
                minlen = r-l+1;
            }
            v[s[l]]++;
            if(v[s[l]] > 0) cnt--;
            l++;
        }
        r++;
    }
    return startindx == -1 ? "" : s.substr(startindx, minlen);
}