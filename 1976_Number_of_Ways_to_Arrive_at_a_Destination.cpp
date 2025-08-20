#include<bits/stdc++.h>
using namespace std;


int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n);
    for(int i=0; i<roads.size(); i++){
        int u = roads[i][0];
        int v = roads[i][1];
        int wt = roads[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({v, wt});
    }

    vector<int> ways(n, 0);
    vector<int> dist(n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int mod = (int)(1e9 + 7);

    ways[0] = 1;
    dist[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        for (auto iter : adj[node]){
            int adjnode = iter.first;
            int dis = iter.second;

            if(dis + wt < dist[adjnode]){
                dist[adjnode] = dis + wt;
                ways[adjnode] = ways[node] ;
                pq.push({dis + wt, adjnode});
            }

            else if (dist[node] == dist[adjnode]){
                ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
            }
        }

    }

    return ways[n-1] % mod;
}