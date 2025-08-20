#include<bits/stdc++.h>
using namespace std;

int sumOfTheDigitsOfHarshadNumber(int x) {
    int a = x;
    int s = 0;
    while (a != 0){
        s += (a%10);
        a /= 10;
    }        

    if (x % s == 0){return s;}
    return -1;
}