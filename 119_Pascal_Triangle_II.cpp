#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev = {1};
        for (int i=0; i<rowIndex; i++){
            vector<int> curr(prev.size());
            curr[0] = 1;
            for (int i=1; i<prev.size(); i++){
                curr[i] = prev[i-1] + prev[i];
            }
            curr.push_back(1);
            prev = curr;
        }

        return prev;
    }

    // using binomial theorem
    // i th element is nCi
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        long long res = 1 ;
        result.push_back(1);
        for(int i=0; i<rowIndex; i++){
            res = res * (rowIndex - i);
            res /= (i+1);
            result.push_back(res);    
        }
        return result ;
    }
};