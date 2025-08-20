#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* fintkthnode(ListNode* temp, int k){
    int cnt = 1;
    while(temp != NULL){
        if (cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}


ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || k == 0) return head;
    ListNode* tail = head;
    int len = 1;
    while (tail->next != NULL){
        tail = tail->next;
        len++;
    }

    k = k % len;
    if (k == 0) return head;

    tail->next = head;
    ListNode* newlastnode = fintkthnode(head, len-k);
    head = newlastnode->next;
    newlastnode->next = nullptr;
    return head;
}