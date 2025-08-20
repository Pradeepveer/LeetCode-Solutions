#include<bits/stdc++.h>
using namespace std;


class MyQueue {
public:
    MyQueue() {
                
    }
    
    void push(int x) {
        s1.push(x);
        
    }
    
    int pop() {
        int val;
        move();
        val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        move();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() & s2.empty();
    }

    private:
        stack<int> s1;
        stack<int> s2;
        void move(){
            if (s1.empty() == false){
                int n1 = s1.size();
                for (int i=0; i<n1; i++){
                    s2.push(s1.top());
                    s1.pop();
                }
        }
    }
};