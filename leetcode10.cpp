#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        //return mymatch(s, p, 0, 0);
        return match_dp(s, p);
    }

private:
    bool mymatch(string s, string p, int i, int j){
        if(j == p.length())
            return (i == s.length());

        bool first_match=false;
        if(i < s.length() && (p[j] == '.' || p[j] == s[i]))
            first_match = true;

        if(j<(p.length()-1) && p[j+1]=='*'){
            return mymatch(s, p, i, j+2) || (first_match && mymatch(s, p, i+1, j));
        }
        else{
            return first_match && mymatch(s, p, i+1, j+1);
        }
    }

    bool match_dp(string s, string p){
        vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1, false));

        dp[s.length()][p.length()] = true;
        for(int i=s.length(); i>=0; i--){
            for(int j=p.length()-1; j>=0; j--){
                bool first_match = false;
                if(i<s.length() && (p[j]=='.' || p[j]==s[i]))
                    first_match=true;

                if((j+1)<p.length() && p[j+1]=='*')
                    dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j]);
                else 
                    dp[i][j] = first_match && dp[i+1][j+1];
            }
        }

        return dp[0][0];
    }
};

int main(){
    string s = "aaaaaaaaaaaab";
    string p = "a*a*a*a*a*a*a*a*a*a*c";

    Solution S;
    cout<<S.isMatch(s, p)<<endl;

    system("pause");
    return 0;

    
}