#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    unordered_map<char, int> smap;

    if (s.size() != t.size()){
        return false;
    }

    for (const char c : s){
        if (smap.count(c)){
            smap[c] += 1;
        }
        else {
            smap[c] = 1;
        }
    }        

    for (const char c : t){
        if (smap.count(c)){
            if (smap[c] == 0){
                return false;
            }
            smap[c] -= 1;
        }

        else {
            return false;
        }

    }
    return true;
}


// 0ms solution
bool isAnagram(string s, string t) {
       
        if(s.length() != t.length()){
            return false;
        }
        int arr1[26] = {0};
        int arr2[26] = {0};
        int n = s.length();
        for(int i=0; i<n; i++){
            arr1[int(s[i]-'a')]++;
        }
        for(int i=0; i<n; i++){
            arr2[int(t[i]-'a')]++;
        }
        for(int i=0; i<26; i++){
            if(arr1[i] != arr2[i]){
                return false ;
            }
        }
        return true;

    }