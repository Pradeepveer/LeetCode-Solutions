#include<bits/stdc++.h>
using namespace std;


bool dfs(vector<vector<int>>& graph, vector<int>& color, int sn, int c){
    color[sn] = c;
    for (auto it : graph[sn]){
        if(color[it] == -1){
            if(dfs(graph, color, it, !c) == false) return false;
        }
        else if (color[it] == c) return false;
    }
    return true;
}


bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);

    for (int i=0; i<n; i++){
        if(color[i] == -1){
            if (dfs(graph, color, i, 0) == false) return false;
        }
    }
    return true;
}