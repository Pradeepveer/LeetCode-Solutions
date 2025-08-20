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


int widthOfBinaryTree(TreeNode* root) {
    long width = 0;
    queue<pair<TreeNode*, int>> q;  //<node, index>;
    q.push({root, 0});

    while(!q.empty()){
        long sub = q.front().second;
        long left = 0;
        long right = 0;
        long size = q.size();

        for (int i=0; i<size; i++){
            TreeNode* node = q.front().first;
            long curr = q.front().second - sub;

            if (i == 0) left = curr;
            if (i == size - 1) right = curr;

            if (node->left) {
                q.push({node->left, 2*curr + 1});
            }
            if (node->right){
                q.push({node->right, 2*curr + 2});
            }
            q.pop();
            width = max(width, right - left + 1);
        }
    }
    return (int)width;
} 