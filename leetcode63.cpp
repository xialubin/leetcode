#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if(m == 0)
            return 0;
        for(int i=0;i<m;i++)
            reverse(obstacleGrid[i].begin(), obstacleGrid[i].end());
        reverse(obstacleGrid.begin(), obstacleGrid.end());
        vector<vector<long long>> res(m, vector<long long>(n, 0));
        int start = 1;
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0] == 1)
                start = 0;
            res[i][0] = start;
        }
        start = 1;
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i] == 1)
                start = 0;
            res[0][i] = start;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                res[i][j] = (1-obstacleGrid[i][j]) * ((1-obstacleGrid[i][j-1])*res[i][j-1] + (1-obstacleGrid[i-1][j])*res[i-1][j]);
            }
        }
        return res[m-1][n-1];
    }
};

class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if(m == 0)
            return 0;
        for(int i=0;i<m;i++)
            reverse(obstacleGrid[i].begin(), obstacleGrid[i].end());
        reverse(obstacleGrid.begin(), obstacleGrid.end());
        if(obstacleGrid[0][0] == 1)
            return 0;
        vector<long long> res(n, 0);
        for(int i=0; i<n; i++){
            if(obstacleGrid[0][i] == 1)
                break;
            res[i]=1;
        }
        for(int i=1; i<m; i++){
            if(obstacleGrid[i][0] == 1)
                res[0] = 0;
            //cout<<res[0]<<" ";
            for(int j=1; j<n; j++){
                res[j] = (1-obstacleGrid[i][j]) * ((1-obstacleGrid[i][j-1])*res[j-1] + (1-obstacleGrid[i-1][j])*res[j]);
                //cout<<res[j]<<" ";
            }
            cout<<endl;
        }
        return res[n-1];
    }
};