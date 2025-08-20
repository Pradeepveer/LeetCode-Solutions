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


vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;
    if (root == NULL) return ans;

    unordered_map<TreeNode*, TreeNode*> parent; // node, parent node;
    queue<TreeNode*> q; // for bfs traversal
    q.push(root);

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        if (node->left){
            q.push(node->left);
            parent[node->left] = node;
        }
        if (node->right){
            q.push(node->right);
            parent[node->right] = node;
        }
    }

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> qq;
    qq.push(target);
    visited[target] = true;
    int level = 0;

    while(!qq.empty()){
        int size = qq.size();
        if (level == k) break;
        for (int i=0; i<size; i++){
            TreeNode* curr = qq.front();
            qq.pop();
            
            if (curr->left && !visited[curr->left]){
                qq.push(curr->left);
                visited[curr->left] = true;
            }
            if (curr->right && !visited[curr->right]){
                qq.push(curr->right);
                visited[curr->right] = true;
            }
            if (parent[curr] && !visited[parent[curr]]){
                qq.push(parent[curr]);
                visited[parent[curr]] = true;
            }
        }
        level++;
    }

    while(!qq.empty()){
        ans.push_back(qq.front()->val);
        qq.pop();
    }
    return ans;
}   