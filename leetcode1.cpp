#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        unordered_map<int, int> mymap;
        int len = nums.size();
        for (int i=0; i<len; i++){
            int T = target - nums[i];
            if (mymap.find(T) != mymap.end()){
                res[0] = mymap[T];
                res[1] = i;
                break;
            }
            mymap[nums[i]] = i;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {3,3};
    int target = 6;
    Solution S;
    vector<int> res = S.twoSum(nums, target);
    for (int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    
    system("pause");
    return 0;
}