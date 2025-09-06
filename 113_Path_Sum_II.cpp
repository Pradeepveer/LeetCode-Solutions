#include<bits/stdc++.h>
using namespace std;


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
    void dfs(TreeNode* node, int sum, int target, vector<int>& temp, vector<vector<int>>& ans){
        if (!node->left && !node->right){
            if (sum + node->val == target){
                ans.push_back(temp);
                return;
            }
            return;
        }
        

        if (node->left){
            temp.push_back(node->left->val);
            dfs(node->left, sum + node->val, target, temp, ans);   
            temp.pop_back();
        }
        if (node->right){
            temp.push_back(node->right->val);
            dfs(node->right, sum + node->val, target, temp, ans);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(root->val);
        dfs(root, 0, targetSum, temp, ans);

        return ans;
    }
    
};