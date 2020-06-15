#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x != 0){
            int mod_num = x % 10;
            if(res > INT_MAX / 10 || res == INT_MAX / 10 && mod_num > INT_MAX % 10) return 0;
            if(res < INT_MIN / 10 || res == INT_MIN / 10 && mod_num < INT_MIN % 10) return 0;
            res = res * 10 + mod_num;
            x = x / 10;
        }

        return res;
    }
};

int main(){
    int x;
    Solution S;

    while(cin>>x){
        cout<<S.reverse(x)<<endl;
    }

    system("pause");
    return 0;
}