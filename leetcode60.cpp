#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    int factorial(int n){
        int res = 1;
        for(int i=1 ; i<=n ; i++){
            res = res * i;
        }
        return res;
    }
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=0;i<n;i++){
            nums.push_back((i+1));
        }
        string res;
        int i = 1;
        while(nums.size() != 0){
            //cout<<nums.size()<<endl;
            int fact = factorial(n-i);
            int j = 0;
            while(k>(j+1) * fact)
                j++;
            k = k - j*fact;
            res.push_back(('0'+nums[j]));
            nums.erase(nums.begin()+j);
            i++;
        }
        return res;
    }
};