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

int dfsmaxsum(TreeNode* root, int& sum){
    if (root == NULL) return 0;

    int lsum = max(0, dfsmaxsum(root->left, sum));
    int rsum = max(0, dfsmaxsum(root->right, sum));

    sum = max(sum, root->val + lsum + rsum);
    return root->val + max(lsum, rsum);
}


int maxPathSum(TreeNode* root) {
    int sum = INT_MIN;
    dfsmaxsum(root, sum);    
    return sum;
}