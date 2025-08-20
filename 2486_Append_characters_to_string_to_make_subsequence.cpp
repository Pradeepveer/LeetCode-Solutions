#include<bits/stdc++.h>
using namespace std;


int appendCharacters(string s, string t) {
    if (s==t){return 0;}
    int maxsame = 0;
    for (int i=0; i<s.length(); i++){
    int currentsame = 0;
        if (s[i] == t[0]){
            int l=0;
            for (int k=i; k<s.length() && l<t.length(); k++){
                if (s[k]==t[l]){
                    currentsame += 1;
                    l++;
                }
            }
        }
        if (currentsame>maxsame){
            maxsame = currentsame;
        } 
    }
    return t.length() - maxsame;
}

int appendCharacters(string s, string t){
    int i = 0; // s
    int j = 0; // t
    while (i<s.length() && j<t.length()){
        if (s[i] == t[j]){
            i++;
            j++;
        }

        else {
            i++;
        }
    }
    return t.length() - j;
}