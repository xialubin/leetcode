#include<string>
#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int start = 0;
        while(str[start] == ' ')
            start++;

        if(str[start] != '+' && str[start] != '-' && (str[start] > '9' || str[start] < '0'))
            return 0;
        
        int sign = 1;
        if(str[start] == '-'){
            sign = -1;
            start++;
        }
        else if(str[start] == '+')
            start++;
        
        int p_num = 0;
        int n_num = 0;
        int x = 0;
        for(int i=start; i<str.length(); i++){
            if(str[i] >= '0' && str[i] <= '9'){
                int a = (str[i] - '0');
                if(sign == 1 && (x > INT_MAX / 10 || x == INT_MAX / 10 && a > 7)) return INT_MAX;
                if(sign == -1 && (x < INT_MIN / 10 || x == INT_MIN / 10 && a > 8)) return INT_MIN;
                x = x * 10 + a * (sign);
            }
            else
                break;
        }
        
        if(n_num == 1)
            return ((-1) * x);
        else 
            return x;
    }
};