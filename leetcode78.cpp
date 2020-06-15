#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    void myfunc(vector<int>& res_in, int start, int k, vector<int>& nums){
        res.push_back(res_in);
        for(int i=start;i<k;i++){
            res_in.push_back(nums[i]);
            myfunc(res_in, i+1, k, nums);
            res_in.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res_in;
        myfunc(res_in, 0, nums.size(), nums);

        return res;
    }
};