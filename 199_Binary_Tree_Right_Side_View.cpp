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


vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    queue<pair<TreeNode*, int>> q; // <node, column>
    map<int, int> mpp; // <column, val>
    if (root == NULL) return ans;
    q.push({root, 0});

    while(!q.empty()){
        TreeNode* node = q.front().first;
        int row = q.front().second;
        mpp[row] = node->val;
        q.pop();

        if (node->left) q.push({node->left, row+1});
        if (node->right) q.push({node->right, row+1});
    }

    for (auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}