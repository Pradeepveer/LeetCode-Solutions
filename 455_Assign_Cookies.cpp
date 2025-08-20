#include<bits/stdc++.h>
using namespace std;


int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end()); 
    sort(s.begin(), s.end());
    int l=0, r=0;
    
    while(l < s.size()){
        if (s[l] >= g[r]) r++;
        l++;
    }
    return r;
}
