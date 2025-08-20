#include<bits/stdc++.h>
using namespace std;


// converting int to string then checking
bool isPalindrome(int x) {
        string s = to_string(x);
        int l = s.length();
        for (int i=0; i<(l/2); i++){
            if (s[i] != s[l-i-1]){return false;}
        }      
        return true;  
}

// reversing the entire number and checking with orginal value
bool isPalindrome(int x){
    long long reverse = 0;
    long long original;
    if(x>=0) {   // negative numbers not palindrome
        original = x;
        while (x != 0){
            reverse = reverse*10 + x%10;
            x /= 10; 
        }
        if (original == reverse){return true;}
    }
    return false;
}

// reversing half of number
// for even digits left half == reverse right half
// for odd digits do not consider center digit
bool isPalindrome(int x){
    // negative int not palindrome and multiple of 10 not palindrome
    if (x<0 || (x!=0 && x%10 == 0)){return false;}

    int reverse = 0;
    while (x>reverse){
        reverse = reverse * 10 + x%10;
        x /= 10;
    }
    return (x == reverse) || (x == reverse/10);
}