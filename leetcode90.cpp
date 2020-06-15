#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    void myfunc(vector<int>& nums, vector<int>& res_in, int start, int len){
        res.push_back(res_in);
        for(int i=start; i<len; i++){
            int j = i;
            int num = 0;
            while(j<len-1 && nums[j] == nums[j+1]){
                res_in.push_back(nums[j]);
                j++;
                num++;
            }
            res_in.push_back(nums[j]);
            myfunc(nums, res_in, j+1, len);
            res_in.pop_back();
            while(num>0){
                res_in.pop_back();
                num--;
            }
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0)
            return res;
        sort(nums.begin(), nums.end());
        vector<int> res_in;
        res.clear();
        res_in.clear();
        myfunc(nums, res_in, 0, nums.size());
        return res;
    }
};
