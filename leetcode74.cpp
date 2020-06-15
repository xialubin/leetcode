#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        if(n == 0)
            return false;
        int row_start = 0;
        int row_end = m-1;
        while(row_start <= row_end){
            int row_mid = row_start + (row_end - row_start) / 2;
            if(matrix[row_mid][n-1] == target)
                return true;
            else if(matrix[row_mid][n-1] < target)
                row_start = row_mid + 1;
            else  // matrix[row_mid][n-1] > target
                row_end = row_mid - 1;
        }

        if(row_start >= m)
            return false;
        
        int col_start = 0;
        int col_end = n-1;
        while(col_start<=col_end){
            int col_mid = col_start + (col_end - col_start) / 2;
            if(matrix[row_start][col_mid] == target)
                return true;
            else if(matrix[row_start][col_mid] < target)
                col_start = col_mid + 1;
            else  // matrix[row_start][col_mid] > target
                col_end = col_mid - 1;
        }

        return false;
    }
};