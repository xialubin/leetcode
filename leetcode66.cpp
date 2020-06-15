#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 0;
        vector<int> res;
        res.clear();
        for(int i=digits.size()-1;i>=0;i--){
            if(i == (digits.size()-1)){
                res.push_back((digits[i]+1)%10);
                c = (digits[i]+1)/10;
            }
            else{
                res.push_back((digits[i]+c)%10);
                c = (digits[i]+c)/10;
            }
        }
        if(c == 1)
            res.push_back(1);

        reverse(res.begin(), res.end());
        
        return res;
    }
};