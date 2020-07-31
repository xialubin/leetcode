#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
private:
    vector<unordered_map<char, int>> row_m = vector<unordered_map<char, int>> (9);
    vector<unordered_map<char, int>> col_m = vector<unordered_map<char, int>> (9);
    vector<unordered_map<char, int>> block_m = vector<unordered_map<char, int>> (9);
    bool fg = false;

    void backward(vector<vector<char>>& board, int i, int j){
        if(i >=9){
            fg = true;
            return;
        }
        int next_i = i + (j+1)/9;
        int next_j = (j+1) % 9;
        if(board[i][j] != '.')
            backward(board, next_i, next_j);
        else{
            for(int k=1; k<=9; k++){
                char c = '0' + k;
                //cout<<c<<endl;
                if(row_m[i].find(c) == row_m[i].end() && col_m[j].find(c) == col_m[j].end() && block_m[(i/3)*3+j/3].find(c) == block_m[(i/3)*3+j/3].end()){
                    board[i][j] = c;
                    row_m[i].insert(make_pair(c, 1));
                    col_m[j].insert(make_pair(c, 1));
                    block_m[(i/3)*3+j/3].insert(make_pair(c, 1));
                    backward(board, next_i, next_j);
                    if(fg)
                        return;
                    else{
                        board[i][j] = '.';
                        row_m[i].erase(c);
                        col_m[j].erase(c);
                        block_m[(i/3)*3+j/3].erase(c);
                    }
                }
            }
        }

        return;
        
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {

        int m = board.size();  //行
        int n = board[0].size();  //列

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                char c = board[i][j];
                if(c != '.'){
                    row_m[i].insert(make_pair(c, 1));
                    col_m[j].insert(make_pair(c, 1));
                    block_m[(i/3)*3+j/3].insert(make_pair(c, 1));
                }
            }
        }

        backward(board, 0, 0);

        return;

        
    }
};