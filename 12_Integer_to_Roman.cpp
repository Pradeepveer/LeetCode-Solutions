#include<bits/stdc++.h>
using namespace std;

string intToRoman(int x){
    int a = x % 10;
    string r = "";
    switch (a) {
        case 1 : r = "I"; break;
        case 2 : r = "II"; break;
        case 3 : r = "III"; break;
        case 4 : r = "IV"; break;
        case 5 : r = "V"; break;
        case 6 : r = "VI"; break;
        case 7 : r = "VII"; break;
        case 8 : r = "VIII"; break;
        case 9 : r = "IX"; break;
    }

    x /= 10;
    if (x != 0){
        a = x % 10;
        switch(a){
            case 1 : r = "X"  + r; break;
            case 2 : r = "XX" + r; break;
            case 3 : r = "XXX" + r; break;
            case 4 : r = "XL" + r; break;
            case 5 : r = "L" + r; break;
            case 6 : r = "LX" + r; break;
            case 7 : r = "LXX" + r; break;
            case 8 : r = "LXXX" + r; break;
            case 9 : r = "XC" + r; break; 
        }
    }
    else {return r;}

    x /= 10;
    if (x != 0){
        a = x % 10;
        switch(a){
            case 1 : r = "C" + r; break; 
            case 2 : r = "CC" + r; break;
            case 3 : r = "CCC" + r; break;
            case 4 : r = "CD" + r; break;
            case 5 : r = "D" + r; break;
            case 6 : r = "DC" + r; break;
            case 7 : r = "DCC" + r; break;
            case 8 : r = "DCCC" + r; break;
            case 9 : r = "CM" + r; break;
        }
    }
    else {return r;}

    x /= 10;
    if (x != 0){
        a = x % 10;
        switch (a) {
            case 1 : r = "M" + r; break;
            case 2 : r = "MM" + r; break;
            case 3 : r = "MMM" + r; break;
        }
    }
    return r;
}

string intToRoman(int num) {
        // Define the values and their corresponding Roman numerals
        vector<pair<int, string>> values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        // Resultant Roman numeral string
        string result;

        // Iterate over the values
        for (const auto &value : values) {
            while (num >= value.first) {
                result += value.second; // Append the Roman numeral
                num -= value.first;     // Subtract the value from num
            }
        }

        return result;
    }