#include<bits/stdc++.h>
using namespace std;


int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> mineffort(n, vector<int>(m, 1e9));
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    mineffort[0][0] = 0;
    pq.push({0, {0, 0}});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int effort = it.first;
        int r = it.second.first;
        int c = it.second.second;

        if (r == n-1 && c == m-1) return effort;
        for (int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < n && nr >=0 && nc >=0 && nc < m){
                int eff = max(abs(heights[r][c] - heights[nr][nc]), effort);
                if (eff < mineffort[nr][nc]){
                    mineffort[nr][nc] = eff;
                    pq.push({eff, {nr, nc}});
                }
            }
        }
    }

    return 0;
}