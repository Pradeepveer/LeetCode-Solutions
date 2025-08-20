#include<bits/stdc++.h>
using namespace std;


vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    stack<int> st;

    for (int i=0; i<asteroids.size(); i++){
        bool destroyed = false;
        while(!st.empty() && st.top() > 0 && asteroids[i] < 0){
            if (abs(st.top()) > abs(asteroids[i])){
                destroyed = true;
                break;
            }
            else if (abs(st.top()) == abs(asteroids[i])){
                st.pop();
                destroyed = true;
                break;
            }
            else {
                st.pop();
            }
        }
        if (!destroyed) st.push(asteroids[i]);
    }
    while(!st.empty()){
        ans.insert(ans.begin(), st.top());
        st.pop();
    }
    return ans;
}