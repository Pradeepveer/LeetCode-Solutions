#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = nullptr;
    
    while (temp != NULL){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* newhead = reverseList(slow->next);

    ListNode* first = head;
    ListNode* second = newhead;

    while (second != NULL){
        if (first->val != second->val){
            reverseList(newhead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseList(newhead);
    return true;
}