#include<bits/stdc++.h>

using namespace std;

bool needle_check(char *h, char *n, int l){
    for (int i=0; i<l; i++){
        if (*(h+i) != *(n+i)){return false;}
    }
    return true;
}

int strStr(string haystack, string needle) {
    for(int i=0; i<haystack.length(); i++){
        bool x;
        if (haystack[i] == needle[0]){
            x = needle_check(&haystack[i], &needle[0], needle.length());
            if (x == true){return i;}
        }
        
    }
    return -1;
}


