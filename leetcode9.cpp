#include<iostream>
#include<limits.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int num = x;
        
        long x_p = 0;
        while(num != 0){
            int a = num % 10;
            x_p = x_p * 10 + a;
            num = num / 10;
        }

        if(x == int(x_p))
            return true;
        else 
            return false;
        
    }
};