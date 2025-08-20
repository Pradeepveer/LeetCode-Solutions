#include<bits/stdc++.h>
using namespace std;


int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    
    for(int i=0; i<n; i++){
        int u = flights[i][0];
        int v = flights[i][1];
        int price = flights[i][2];
        adj[u].push_back({v, price});
    }
    
    vector<int> price(n, 1e9);
    queue<pair<int, pair<int, int>>> q; // {stops, {node, cost}}

    price[src] = 0;
    q.push({0, {src, 0}});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops > k) continue;
        for(auto it : adj[node]){
            int adjnode = it.first;
            int wt = it.second;
            if (cost + wt < price[adjnode] && stops <=k){
                price[adjnode] = cost + wt;
                q.push({stops + 1, {adjnode, cost + wt}});
            }
        }
    }
    if (price[dst] == 1e9) return -1;
    return price[dst];
}