#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ss;
        ss = ss + "%";
        for(int i=0; i<s.length(); i++){
            ss.push_back('#');
            ss.push_back(s[i]);
        }
        ss.push_back('#');  

        int r_len=0, mx=1, c_len=0;
        vector<int> half_len(ss.length());
        for(int id=1; id<ss.length(); id++){
            if(id > mx){
                while(id+c_len<ss.length() && ss[id-c_len] == ss[id+c_len])
                    c_len++;
                c_len--;
                mx = id + c_len;
                r_len = c_len;
                half_len[id] = c_len;
            }
            else{
                c_len = half_len[2*(mx-r_len) - id];
                if((id+c_len) >= mx){
                    c_len = mx - id;
                    while(id+c_len<ss.length() && ss[id-c_len] == ss[id+c_len])
                        c_len++;
                    c_len--;
                    mx = id + c_len;
                    r_len = c_len;
                    half_len[id] = c_len;
                }
                else{
                    half_len[id] = c_len;
                }
            }
        }

        int mx_id = 0;
        int mx_len = 0;
        for(int i=0; i<ss.length(); i++){
            if(half_len[i] > mx_len){
                mx_id = i;
                mx_len = half_len[i];
            }
        }

        int left = mx_id - mx_len;
        int right = mx_id + mx_len;

        string res;
        for(int i=left; i<=right; i++){
            if(ss[i] != '#'){
                res.push_back(ss[i]);
            }
        }

        return res;
        
    }
};

int main(){
    string s = "a";
    Solution S;
    string res = S.longestPalindrome(s);
    cout<<res<<endl;

    system("pause");
    return 0;
}