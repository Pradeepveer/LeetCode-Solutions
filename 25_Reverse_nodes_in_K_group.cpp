#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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


ListNode* getkthnode(ListNode* temp, int k){
    k -= 1;
    while (temp != NULL && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    ListNode* prevlast = NULL;

    while(temp != NULL){
        ListNode* knode = getkthnode(temp, k);
        if (knode == NULL){
            if (prevlast) prevlast->next = temp;
            break;
        }
        ListNode* nextnode = knode->next;
        knode->next = NULL;
        reverseList(temp);
        if (temp == head){
            head = knode;
        }
        else {
            prevlast->next = knode;
        }
        prevlast =temp;
        temp = nextnode;
    }
    return head;
}