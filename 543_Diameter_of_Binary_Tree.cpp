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


int dfsdiameter(TreeNode* root, int& diameter){
    if (root == NULL) return 0;

    int lh = dfsdiameter(root->left, diameter);
    int rh = dfsdiameter(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return max(lh, rh) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    dfsdiameter(root, diameter);
    return diameter;        
}