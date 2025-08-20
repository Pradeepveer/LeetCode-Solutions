#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    int i = 0;
    char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    for (int j=0; j<s.length(); j++){
        // converting I = 1, IV = 4, IX = 9
        if (s[j] == 'I'){
            if (s[j+1] == 'V'){
                i += 4;
                j++;
            }

            else if (s[j+1] == 'X'){
                i += 9;
                j++;
            }

            else {i += 1;};
        }

        // converting V = 5
        else if (s[j] == 'V'){i += 5;}

        // converting X = 10, XL = 40, XC = 90
        else if (s[j] == 'X'){
            if (s[j+1] == 'L'){
                i += 40;
                j++;
            }

            else if (s[j+1] == 'C'){
                i += 90;
                j++;
            }

            else {i += 10;}
        }
            
        // converting L = 50
        else if (s[j] == 'L'){i += 50;}

        // converting C = 100, CD = 400, CM = 900
        else if (s[j] == 'C'){
            if (s[j+1] == 'D'){
                i += 400;
                j++;
            }

            else if (s[j+1] == 'M'){
                i += 900;
                j++;
            }

            else {i += 100;}
        }

        // conoverting D = 500
        else if (s[j] == 'D'){i += 500;}

        // conoverting M = 1000
        else if (s[j] == 'M'){i += 1000;}
    }

    return i;
}

// using hashmap (slower than if-else)
int romanToInt(string s) {
    unordered_map<char, int> map;

    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    int ans = 0;
    int l = s.length();
     
    for (int i=0; i<l; i++){
        if (map[s[i]] < map[s[i+1]]){
            ans -= map[s[i]];
        }

        else {
            ans += map[s[i]];
        }
    }
    return ans;
}

// using #define and switch case
#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

int char_to_num(char c){
    switch (c){
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    }
    return 0;
}

int romanToInt(string s){
    int ans = 0;
    int prev = 0;
    int l = s.length();

    for (int i=l-1; i>0; --i){
        int value1 = char_to_num(s[i]);
        if (value1 < prev){
            value1 *= -1;
        }
        ans += value1;
        prev = value1;        
    }
    return ans;
}