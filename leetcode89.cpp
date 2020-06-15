#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include "limits.h"

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return vector<int>(1, 0);
        vector<int> res = {0,1};
        if(n == 1) return res;

        int add_num = 1;
        for(int i=2; i<=n; i++){
            add_num = add_num * 2;
            int res_size = res.size();
            for(int j=res_size-1; j>=0; j--){
                res.push_back(res[j]+add_num);
            }
        }
        return res;
    }
};