#include<iostream> 
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0)
            return 0;
        int col = grid[0].size();
        if(col==0)
            return 0;
        vector<vector<int>> bp(row, vector<int>(col));
        bp[0][0] = grid[0][0];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0) continue;
                else if(i==0 && j>0) bp[i][j] = bp[i][j-1] + grid[i][j];
                else if(i>0 && j==0) bp[i][j] = bp[i-1][j] + grid[i][j];
                else{  //i>0 && j>0
                    bp[i][j] = min(bp[i][j-1] + grid[i][j], bp[i-1][j] + grid[i][j]);
                }
            }
        }
        
        int res = bp[row-1][col-1];
        return res;
    }
};
