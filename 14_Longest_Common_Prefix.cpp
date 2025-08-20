#include<bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }

int main(){
    vector<string> strs ={"dog","racecar","car"};
    vector<string >strs1 = {"flower","flow","flight"};
    vector<string >strs2 = {""};
    vector<string >strs3 = {""};
    cout<< "strs :"<< longestCommonPrefix(strs)<<endl;
    cout<< "strs1 :"<< longestCommonPrefix(strs1)<<endl;
    cout<< "strs2 :"<< longestCommonPrefix(strs1)<<endl;
    cout<< "strs3 :"<< longestCommonPrefix(strs1)<<endl;
    return 0;
}