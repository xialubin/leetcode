#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
private:
    int num_left_p = 0, num_right_p=0;
    char parenthese[2] = {'(', ')'};
    vector<string> res;

    void recc_generator(string& str, int i, int n){
        if(i == n ){
            if(num_left_p == (n/2) && num_right_p == (n/2))
                res.push_back(str);
            return;
        }

        if(num_left_p < num_right_p)
            return;
        
        if(num_left_p == (n/2)){
            res.push_back(str);
            while(i<n){
                res.back().push_back(')');
                i++;
            }
            return;
        }

        for(auto p: parenthese){
            if(p == '('){
                num_left_p += 1;
                str.push_back(p);
                recc_generator(str, i+1, n);
                str.pop_back();
                num_left_p -= 1;
            }
            else{
                num_right_p += 1;
                str.push_back(p);
                recc_generator(str, i+1, n);
                str.pop_back();
                num_right_p -= 1;
            }
        }

        return;

    }
public:
    vector<string> generateParenthesis(int n) {
        string str = "";
        recc_generator(str, 0, n*2);

        return res;
    }
};

int main(){
    int n = 3;
    Solution S;
    vector<string> res = S.generateParenthesis(n);

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<endl;
    }

    system("pause");
    return 0;
}