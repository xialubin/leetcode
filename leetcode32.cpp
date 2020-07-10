#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        stack<int> s_ind;
        for(int i=0; i<s.length(); i++){
            if(st.empty()){
                st.push(s[i]);
                s_ind.push(i);
            }
            else if(s[i] == ')' && st.top() == '('){
                st.pop();
                s_ind.pop();
            }
            else{
                st.push(s[i]);
                s_ind.push(i);
            }
        }

        if(s_ind.empty())
            return s.length();
        else{
            s_ind.push(s.length());
            int num = s.length();
            int max_num = 0;
            while(!s_ind.empty()){
                max_num = max(max_num, (num-s_ind.top()-1));
                num = s_ind.top();
                s_ind.pop();
            }

            max_num = max(max_num, num);

            return max_num;
        }
    }
};

int main(){
    string ss = ")()(()())";
    Solution S;
    cout<<S.longestValidParentheses(ss)<<endl;

    system("pause");
    return 0;
    
}