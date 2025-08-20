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
        ListNode* prev = new ListNode(-1);
        prev->next = head;

        while(head->next && head->val == head->next->val){
            if (head->val == head->next->val){
                int value = head->val;
                while (head->val == value){
                    if (head->next == NULL) return NULL;
                    head = head->next;
                }
            }
        }

        while(temp && temp->next){
            int value = temp->val;
            if (value == temp->next->val){
                while (temp->val == value){
                    if(temp->next == NULL){
                        prev->next = nullptr;
                        return head;
                    }
                    temp = temp->next;
                }
                prev->next = temp;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        
        return head;
    }
};