#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int i=0, j=1;
        while(j<nums.size()){
            if(nums[j] == nums[i]){
                j++;
            }
            else{
                nums[i+1] = nums[j];
                j++;
                i++;
            }
        }

        return i+1;
        
    }
};

int main(){
    vector<int> nums;
    Solution S;
    cout<<S.removeDuplicates(nums)<<endl;

    system("pause");
    return 0;
}