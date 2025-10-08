#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;

        for (int i=0; i<n; i++){
            int low = 0; 
            int high = m-1;
            long long s_spell = (long long)spells[i];
            while(low <= high){
                int mid = low + (high - low)/2;
                long long s_potion = (long long)potions[mid];
                if (s_spell * s_potion >= success) high = mid - 1;
                else low = mid + 1;
            }
            ans.push_back(m-low);
        }

        return ans;
    }
};