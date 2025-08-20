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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode* dummyhead = new ListNode(-1);
        ListNode* tail = dummyhead;

        while(temp1 != NULL && temp2 != NULL){
            if (temp1->val <= temp2->val){
                tail->next = temp1;
                temp1 = temp1->next;
                tail = tail->next;
            }
            else{
                tail->next = temp2;
                temp2 = temp2->next;
                tail = tail->next;
            }
        }

        while(temp1){
            tail->next = temp1;
            temp1 = temp1->next;
            tail = tail->next;
        }

        while(temp2){
            tail->next = temp2;
            temp2 = temp2->next;
            tail = tail->next;
        }

        ListNode* head = dummyhead->next;
        dummyhead->next = nullptr;
        delete(dummyhead);

        return head;
    }
};