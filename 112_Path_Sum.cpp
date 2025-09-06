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
    bool dfs(TreeNode* node, int sum, int target){
        if (!node->left && !node->right){
            if (sum + node->val == target) return true;
            return false;
        }
        bool left, right;
        if (node->left) left = dfs(node->left, sum + node->val, target);
        if (node->right) right = dfs(node->right, sum + node->val, target);

        return left || right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return dfs(root, 0, targetSum);
    }
};