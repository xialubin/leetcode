#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<int>> c = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
    int m=0, n=0;
    bool myfunc(vector<vector<char>>& board, string& word, int i, int j, int k, vector<vector<bool>>& visited){
        if(board[i][j] == word[k]){
            visited[i][j] = true;
            k++;
            if(k == word.size())
                return true;
        }
        else 
            return false;
        
        bool res = false;
        for(int p=0;p<4;p++){
            int next_i = i + c[p][0];
            int next_j = j + c[p][1];
            if(next_i < m && next_i >=0 && next_j < n && next_j >=0 && visited[next_i][next_j] == false)
                res = res || myfunc(board, word, i+c[p][0], j+c[p][1], k, visited);
        }
        visited[i][j] = false;

        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if(m == 0)
            return false;
        if(word.size() == 0)
            return false;
        n = board[0].size();
        if(n == 0)
            return false;

        bool res = false;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res = myfunc(board, word, i, j, 0, visited);
                if(res)
                    return res;
            }
        }

        return res;
        
    }
};