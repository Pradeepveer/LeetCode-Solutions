#include<bits/stdc++.h>
using namespace std;



void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int nodes, int sn){
    queue<int> q;
    q.push(sn);
    visited[sn] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vector<int> temp = isConnected[node];
        for(int i=0; i<temp.size(); i++){
            if (temp[i] == 1 && !visited[i]){
                visited[i] = 1;
                dfs(isConnected, visited, nodes, i);
            }
        }        
    }
}

// isConnected adj matrix
// 0 based index
int findCircleNum(vector<vector<int>>& isConnected) {
    int nodes = isConnected.size();
    vector<int> visited(nodes, 0);
    int provinces = 0;

    for (int i=0; i<nodes; i++){
        if (visited[i] == 0){
            provinces++;
            dfs(isConnected, visited, nodes, i);
        }
    }
    return provinces;
}


