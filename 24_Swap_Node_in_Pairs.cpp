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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        // swap head and next node;
        ListNode* node1 = head->next;
        head->next = node1->next;
        node1->next = head;
        head = node1;

        // swap till last node;
        // back->n1->n2->front   ==>   back->n2->n1->front
        ListNode* back = head->next;
        while(back->next != NULL && back->next->next != NULL){
            ListNode* n1 = back->next;
            ListNode* n2 = back->next->next;
            back->next = n2;

            if (n2->next == NULL){
                n2->next = n1;
                n1->next = nullptr;
            }

            else{
                ListNode* front = n2->next;
                n2->next = n1;
                n1->next = front;
            }

            back = n1;
        }

        return head;
    }
};