#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 

void preorder(TreeNode* root, vector<int>& pre){
    if(root == NULL) return;
    if(root->left) preorder(root->left, pre);
    pre.push_back(root->val);
    if (root->right) preorder(root->right, pre);
    return;
}

int kthSmallest(TreeNode* root, int k) {
    int cnt = 0;
    vector<int> pre;
    preorder(root, pre);
    return pre[k-1];
}