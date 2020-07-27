#include<unordered_map>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> row(9);
        vector<unordered_map<char, int>> col(9);
        vector<unordered_map<char, int>> block(9);

        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                char c = board[i][j];
                if(c == '.')
                    continue;
                int block_id = (i/3)*3+j/3;
                if(row[i].find(c) == row[i].end() && col[j].find(c) == col[j].end() && block[block_id].find(c) == block[block_id].end()){
                    row[i].insert(make_pair(c, 1));
                    col[j].insert(make_pair(c, 1));
                    block[block_id].insert(make_pair(c, 1));
                }
                else{
                    cout<<"i: "<<i<<"j: "<<j<<endl;
                    return false;
                }
            }
        }

        return true;
    }
};