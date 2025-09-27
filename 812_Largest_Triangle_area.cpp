#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double area (int x1, int y1, int x2, int y2, int x3, int y3){
        double a1 = (double)x1;
        double b1 = (double)y1;
        double a2 = (double)x2;
        double b2 = (double)y2;
        double a3 = (double)x3;
        double b3 = (double)y3;

        return abs(0.5 * (a1 * (b2 - b3) + a2 * (b3 - b1) + a3 * (b1 - b2)));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxi = 0;
        int n = points.size();
        for (int i=0; i<n-2; i++){
            for (int j=i+1; j<n-1; j++){
                for (int k=j+1; k<n; k++){
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    double curarea = area(x1, y1, x2, y2, x3, y3);
                    maxi = max(maxi, curarea);
                }
            }
        }
        return maxi;
    }
};