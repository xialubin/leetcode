#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<limits.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        if(n == 0)
            return "";

        string res="";
        int shortest_len = INT_MAX;
        for(auto e:strs){
            shortest_len = min(int(e.length()), shortest_len);
        }

        char c;
        for(int j=0; j<shortest_len; j++){
            c = strs[0][j];
            res.push_back(c);
            for(int i=1; i<n; i++){
                if(strs[i][j] != c){
                    res.pop_back();
                    break;
                }
            }
            if(res.size() != j+1)
                break;
        }

        return res;
        
    }
};

int main(){
    vector<string> strs;
    strs.push_back("aca");
    strs.push_back("cba");

    Solution S;
    cout<<S.longestCommonPrefix(strs)<<endl;

    system("pause");
    return 0;
}
