#include<bits/stdc++.h>
using namespace std;


struct Node{
    Node* links[2];

    Node(){
        links[0] = nullptr;
        links[1] = nullptr;
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }

    bool containsKey(int bit){
        return links[bit] != NULL;
    }
};


class Trie{
    private : Node* root;

    public:
        Trie(){
            root = new Node();
        }

        void insert(int num){  
            Node* node = root;

            for (int i=31; i>=0; i--){
                int bit = (num >> i) & 1;
                if(!node->containsKey(bit)){
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }

        int maxXor(int num){
            Node* node = root;
            int ans = 0;
            for (int i=31; i>=0; i--){
                int bit = (num >> i) & 1;
                if (node->containsKey(1-bit)){
                    ans = ans | (1LL << i);
                    node = node->get(1-bit);
                }
                else node = node->get(bit);
            }
            return ans;
        }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        Trie trie;
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> oq;
        int q = queries.size();
        for (int i=0; i<q; i++){
            oq.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(oq.begin(), oq.end());
        vector<int> ans(q);
        int ind = 0;
        for(int i=0; i<q; i++){
            int ai = oq[i].first;
            int xi = oq[i].second.first;
            int qi = oq[i].second.second;

            while(ind < n && nums[ind] <= ai){
                trie.insert(nums[ind]);
                ind++;
            }

            if (ind == 0) ans[qi] = -1;
            else ans[qi] = trie.maxXor(xi);
        }
        return ans;
    }
};