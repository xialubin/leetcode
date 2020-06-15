#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i=0;i<m;i++)
            res[i][0] = 1;
        for(int i=0;i<n;i++)
            res[0][i] = 1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                res[i][j] = res[i][j-1] + res[i-1][j];
            }
        }
        return res[m-1][n-1];
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<int> res(n, 1);
        for(int i=1;i<m;i++){  // 从0开始的话就多算了一行，相当于算m+1，n的值了
            for(int j=1;j<n;j++){
                res[j] = res[j-1] + res[j];
            }
        }
        return res[n-1];
    }
};