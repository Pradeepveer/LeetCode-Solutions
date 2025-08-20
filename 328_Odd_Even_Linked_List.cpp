#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* oddEvenList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenhead = even;
    while (even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenhead;
    return head;
}