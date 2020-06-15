#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include "limits.h"

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        int nums1_len = nums1.size();
        for(int i=m; i<nums1_len; i++){
            nums1.erase(nums1.begin() + i);
        }
        for(int i=0; i<n; i++){
            while(j<nums1.size() && nums2[i] >= nums1[j])
                j++;
            nums1.insert(nums1.begin() + j, nums2[i]);
            j++;
        }
        return;
    }
};