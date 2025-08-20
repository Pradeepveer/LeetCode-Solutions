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


// Height of Tree
int height(TreeNode* root){
    if (root == NULL) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;

    while(!q.empty()){
        depth++;
        int size = q.size();
        for (int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
        }
    }
    return depth;
}


bool isBalanced(TreeNode* root) {
    if (root == NULL) return true;
    int left = height(root->left);
    int right = height(root->right);
    if (abs(left-right) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
    }
    return false;
}   


int dfsheight(TreeNode* root){
    if (root == NULL) return 0;

    int lh = dfsheight(root->left);
    if (lh == -1) return -1;

    int rh = dfsheight(root->right);
    if (rh == -1) return -1;

    if (abs(rh - lh) > 1) return -1;

    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode* root){
    return dfsheight(root) != -1;
}