#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    string a = "";
    for (char c : s){
        if (int(c) > 64 && int(c) < 91){
            a += tolower(c);
        }

        else if (int(c) > 96 && int(c) < 123){
            a += c;
        }

        else if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' ||
        c == '7' || c == '8' || c == '9' || c == '0'){
            a += c;
        }
    }

    for (int i=0; i<a.length()/2; i++){
        if(a[i] != a[a.length()-i-1]){
            return false;
        }
    }
    return true;
}
