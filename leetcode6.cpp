#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int flag=-1;
        int row_num = 0;
        
        if(numRows >= s.length() || numRows == 1)
            return s;

        vector<string> res_strs(numRows);
        
        for(int i=0; i<s.length(); i++){
            res_strs[row_num].push_back(s[i]);
            if(row_num == 0 || row_num == (numRows - 1)){
                flag = -1 * flag;
                row_num = row_num + flag;
            }
            else{
                row_num = row_num + flag;
            }
        }

        string ss;
        for(int i=0; i<numRows; i++){
            if(res_strs[i].length() != 0){
                ss += res_strs[i];
            }
        }

        return ss;
    }
};