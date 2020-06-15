#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len, 1);
        for(int i=1; i<len; i++){
            int num = (s[i] - '0') + (s[i-1] - '0')*10;
            if(s[i] == '0'){
                if(num <= 26 && num>=1){
                    if(i-2 < 0)
                        dp[i] = 1;
                    else
                        dp[i] = dp[i-2];
                }
                else
                    return 0;
            }
            else{
                if(s[i-1] == '0'){
                    dp[i] = dp[i-1];
                    continue;
                }
                if(num <= 26 && num>=1){
                    if(i-2 < 0)
                        dp[i] = dp[i-1] + 1;
                    else
                        dp[i] = dp[i-1] + dp[i-2];
                }
                else
                    dp[i] = dp[i-1];
            }
        }

        return dp[len-1];
    }
};