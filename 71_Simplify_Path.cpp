#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        string ans = "";
        int i = 0;
        while(i < n){
            if (path[i] == '/'){
                while (i < n && path[i] == '/') i++;
                string str = "";
                while (i < n && path[i] != '/'){
                    str += path[i];
                    i++;
                }
                st.push(str);
            }
        }

        int cnt = 0;
        while(!st.empty()){
            string s = st.top();
            st.pop();

            if (s == "..") cnt++;
            else if (s == ".") continue;
            else {
                if (cnt > 0){
                    cnt--;
                    continue;
                }
                else ans = "/" + s + ans;
            }
        }

        int l = ans.size();
        if (l <= 1) return "/";
        else if (ans[l-1] == '/') ans.pop_back();
        return ans;
    }

};