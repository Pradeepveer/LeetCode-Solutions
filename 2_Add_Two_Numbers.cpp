#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    int carry = 0;

    while(t1 != NULL || t2 != NULL){
        int sum = carry;
        if (t1) sum += t1->val;
        if (t2) sum += t2->val;

        ListNode* newnode = new ListNode(sum % 10);
        carry = sum / 10;
        current->next = newnode;
        current = current->next;
        if (t1) t1 = t1->next;
        if (t2) t2 = t2->next;
    }

    if (carry) {
        ListNode* newnode = new ListNode(carry);
        current->next = newnode;
    }
    return dummy->next;
}