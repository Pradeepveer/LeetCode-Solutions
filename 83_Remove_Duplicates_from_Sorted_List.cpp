#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = head;

        while(temp != NULL && temp->next){
            if (temp->val == temp->next->val){
                ListNode* front = temp->next;
                temp->next = front->next;
                front->next = nullptr;
                delete(front);
            }
            else temp = temp->next;
        }

        return head;
    }
};