#include<bits/stdc++.h>

using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> nummap;
    for (int i=0; i<nums.size(); i++){
        // each occurence of int increases its freq by 1
        nummap[nums[i]]++; 
    }        
    int f = 0;  // freq of an int
    int tf = 0; // total freq = f * no.of element with freq "f"

    for (int j=0; j<nummap.size(); j++){
        // if int have freq > f then f = freq = tf
        if (nummap[j] > f){
            f = nummap[j];
            tf = f;
        }

        else if(nummap[j] == f){
            // if another int have freq f then tf += f
            tf += f;
        }
    }

    return tf;
}

// merging two for loops in above into one for loop
int maxFrequencyElements(vector<int>& nums) {
    int currentf = 0;
    int maxf = 0;  // freq of an int
    int tf = 0; // total freq = f * no.of element with freq "f"

    unordered_map<int, int> nummap;
    for (int num : nums){   // similar to python num in nums
        // each occurence of int increases its freq by 1
        nummap[num]++; 
        currentf = nummap[num];
        if (currentf > maxf){
            maxf = currentf;
            tf = currentf;
        }
        else if (currentf == maxf){
            tf += currentf;
        }
    }        
    return tf;
}