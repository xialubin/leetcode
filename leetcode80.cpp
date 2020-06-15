#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        int num = 1;
        int ele = nums[0];
        int i = 1;
        while(i < len){
            if(nums[i] == ele)
                num++;
            if(num > 2){
                nums.erase(nums.begin()+i);
                len = nums.size();
                num--;
                continue;
            }
            if(nums[i] != ele){
                ele = nums[i];
                num = 1;
            }
            i++;
        }
        return nums.size();

    }
};