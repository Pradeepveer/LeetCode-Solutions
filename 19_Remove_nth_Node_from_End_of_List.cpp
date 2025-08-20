#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    for (int i=0; i<n; i++){
        fast = fast->next;
    }        
    if (fast == NULL) return head->next;

    ListNode* slow = head;
    while (fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}