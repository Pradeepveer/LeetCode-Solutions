#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
};

void insertcopyinbetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* nextelem = temp->next;
        Node* copy = new Node(temp->val);
        copy->next = nextelem;
        temp->next = copy;
        temp = nextelem;
    }
    return;
}


void connectrandom(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copynode = temp->next;
        if(temp->random) copynode->random = temp->random->next;
        else copynode->random = nullptr;
        temp = temp->next->next;
    }
    return;
}


Node* getdeepcopylist(Node* head){
    Node* temp = head;
    Node* dummy = new Node(-1);
    Node* res = dummy;
    while(temp != NULL){
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummy->next;
}

Node* copyRandomList(Node* head) {
    insertcopyinbetween(head);
    connectrandom(head);
    return getdeepcopylist(head);
}