#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         if(m == 0)
//             return;
//         int n=matrix[0].size();
//         if(n == 0)
//             return;
        
//         vector<bool> col_flag(n, false); 
//         bool row_flag=false;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j] == 0){
//                     row_flag = true;
//                     col_flag[j] = true;
//                 }
//             }
//             if(row_flag)
//                 matrix[i] = vector<int>(n, 0);
//             row_flag = false;
//         }

//         for(int j=0;j<n;j++){
//             if(col_flag[j]){
//                 for(int i=0;i<m;i++)
//                     matrix[i][j] = 0;
//             }
//         }

//         return;
//     }
// };

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return;
        int n = matrix[0].size();
        if(n == 0)
            return;

        bool row0 = false;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    if(i == 0){
                        row0 = true;
                        matrix[0][j] = 0;
                    }
                    else{
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for(int i=1; i<m; i++){
            if(matrix[i][0] == 0){
                for(int j=0; j<n; j++)
                    matrix[i][j] = 0;
            }
        }
        for(int j=1; j<n; j++){
            if(matrix[0][j] == 0){
                for(int i=0; i<m; i++)
                    matrix[i][j] = 0;
            }
        }

        if(matrix[0][0] == 0){
            for(int i=0; i<m ;i++)
                matrix[i][0] = 0;
        }
        if(row0){
            for(int j=0; j<n; j++)
                matrix[0][j] = 0;
        }

        return;
    }
};