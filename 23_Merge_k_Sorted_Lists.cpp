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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        bool elementpresent = true;
        while (elementpresent){
            elementpresent = false;
            int indxmin = -1;
            int curmin = INT_MAX;
            for (int i=0; i<k; i++){
                if (lists[i] != NULL){
                    elementpresent = true;
                    if (lists[i]->val <= curmin){
                        curmin = lists[i]->val;
                        indxmin = i;
                    }
                }
            }
            if (elementpresent == false) break;
            else{
                tail->next = lists[indxmin];
                tail = tail->next;
                lists[indxmin] = lists[indxmin]->next;
            }
        }

        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists){
        // store all values in array, sort, make LL
        int k = lists.size();
        if (k == 0) return NULL;

        vector<int> arr;
        for (int i=0; i<k; i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }

        sort(arr.begin(), arr.end());

        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        for (int i=0; i<arr.size(); i++){
            tail->next = new ListNode(arr[i]);
            tail = tail->next;
        }

        return head->next;
    }
};