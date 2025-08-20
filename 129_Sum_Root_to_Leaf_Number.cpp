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



class Solution {
public:
    void f(TreeNode* node, int val, int& total){
        if (node->left == NULL && node->right == NULL){
            total += val*10 + node->val;
            return;
        }

        if (node->left) f(node->left, val*10 + node->val, total);
        if (node->right) f(node->right, val*10 + node->val, total);
    }

    int sumNumbers(TreeNode* root) {
        int total = 0;
        f(root, 0, total);
        return total;
    }
};