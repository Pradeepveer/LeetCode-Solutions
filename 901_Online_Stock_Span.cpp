#include<bits/stdc++.h>
using namespace std;


class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        indx++;
        while(!st.empty() && price >= st.top().first){
            st.pop();
        }
        int ans = indx - (st.empty() ? -1 : st.top().second);
        st.push({price, indx});
        return ans;
    }

    private:
    stack<pair<int, int>> st;   // pair<val, indx>
    int indx = -1;
};