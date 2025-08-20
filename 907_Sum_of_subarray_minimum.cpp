#include<bits/stdc++.h>
using namespace std;


vector<int> findnse(vector<int>& arr){
    vector<int> nse(arr.size());
    stack<int> st;
    int n = arr.size();

    for (int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

vector<int> findpsee(vector<int>& arr){
    vector<int> psee(arr.size());
    stack<int> st;

    for (int i=0; i<arr.size(); i++){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}

int sumSubarrayMins(vector<int>& arr) {
    vector<int> psee = findpsee(arr);
    vector<int> nse = findnse(arr);
    long long sum = 0;
    long long mod = 1e9 + 7;

    for (int i=0; i<arr.size(); i++){
        long long left = (long long)(i - psee[i]);
        long long right = (long long)(nse[i] - i);
        sum = (sum + ((long long)left * right * arr[i]) % mod) % mod;

    }
    return sum;
}