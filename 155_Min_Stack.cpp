#include<bits/stdc++.h>
using namespace std;


class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        long v = val;
        if (s.empty()){
            s.push(val);
            mini = val;
        }

        else{
            if (val > mini) s.push(val);
            else{
                s.push(2*v - mini);
                mini = val;
            }
        }

    }
    
    void pop() {
        if (s.empty()) return;
        long x = s.top();
        s.pop();
        if (x < mini) mini = 2 * mini - x;
    }
    
    int top() {
        if (s.empty()) return -1;
        long x = s.top();
        if (mini < x) return int(x);
        return int(mini);        
    }
    
    int getMin() {
        return int(mini);
    }

    private:
    long mini = INT_MAX;
    stack<long> s;
};
