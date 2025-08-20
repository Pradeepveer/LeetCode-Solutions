#include<bits/stdc++.h>
using namespace std;


int candy(vector<int>& ratings) {
    int sum = 1;
    int i = 1;
    while(i < ratings.size()){
        if (ratings[i] == ratings[i-1]){
            sum++;
            i++;
        }

        int peak = 1;
        while(i<ratings.size() && ratings[i] > ratings[i-1]){
            peak++;
            sum += peak;
            i++;
        }

        int down = 1;
        while(i<ratings.size() && ratings[i] < ratings[i-1]){
            sum += down;
            down++;
            i++;
        }

        if (down > peak) sum += down - peak;
    }        
    return sum;
}
