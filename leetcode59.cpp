#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> change = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<int> cor = {0, 0};
        bool flag = false;
        int i = 0;
        int direct = 0;
        while(i<(n*n)){
            if(cor[0] == n || cor[1] == n || cor[0] < 0 || cor[1] < 0 || res[cor[0]][cor[1]] != 0){
                direct = (direct + 1) % 4;
                cor[0] = cor[0] + change[direct][0];
                cor[1] = cor[1] + change[direct][1];
                if(flag)
                    break;
                flag = true;
            }
            else{
                res[cor[0]][cor[1]] = (i + 1);
                cor[0] = cor[0] + change[direct][0];
                cor[1] = cor[1] + change[direct][1];
                flag = false;
                i++;
            }
        }
        return res;
    }
};