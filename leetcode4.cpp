#include<vector>
#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()){
            nums1.swap(nums2);
        }
        int m = nums1.size();
        int n = nums2.size();

        int p = 0, q = m, half = (m+n+1) / 2;
        while(p <= q){
            int i = p + (q-p) / 2;
            int j = half - i;
            if(i>0 && nums1[i-1] > nums2[j])
                q = i - 1;
            else if(i<m && nums1[i] < nums2[j-1])
                p = i + 1;
            else{
                int maxleft = 0;
                if(i == 0) {maxleft = nums2[j-1];}
                else if(j == 0) {maxleft = nums1[i-1];}
                else{maxleft = max(nums1[i-1], nums2[j-1]);}
                if((m+n)%2 != 0) {return double(maxleft);}

                int minright = 0;
                if(i == m) {minright = nums2[j];}
                else if(j == n) {minright = nums1[i];}
                else{minright = min(nums1[i], nums2[j]);}

                return (double(maxleft) + double(minright)) / 2.0;
            }
        }

        return 0.0;
    }
};

int main(){
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};

    Solution S;
    double r = S.findMedianSortedArrays(nums1, nums2);
    cout<<r<<endl;

    system("pause");
    return 0;
}