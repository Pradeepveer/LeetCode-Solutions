#include<bits/stdc++.h>
using namespace std;

// TC = O(2N) * 26
int characterReplacement(string s, int k) {
    int l = 0, r = 0, maxlen = 0, maxfreq = 0;
    vector<int> v(26, 0);
    while (r < s.size()){
        v[s[r] - 'A']++;
        maxfreq = max(maxfreq, v[s[r] - 'A']);
        while ((r - l + 1) - maxfreq > k){
            v[s[l] - 'A']--;
            maxfreq = 0;
            for (int i=0; i<26; i++) maxfreq = max(maxfreq, v[i]);
            l++;
        }
        
        if ((r - l + 1) - maxfreq <= k){
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }

    return maxlen;
}


// TC = O(N)
int characterReplacement(string s, int k) {
    int l = 0, r = 0, maxlen = 0, maxfreq = 0;
    vector<int> v(26, 0);
    while (r < s.size()){
        v[s[r] - 'A']++;
        maxfreq = max(maxfreq, v[s[r] - 'A']);
        if ((r - l + 1) - maxfreq > k){
            v[s[l] - 'A']--;
            l++;
        }
        
        if ((r - l + 1) - maxfreq <= k){
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }

    return maxlen;
}