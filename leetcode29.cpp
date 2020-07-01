#include<string>
#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;

        int sign = (dividend < 0)^(divisor < 0) ? -1 : 1;
        long long m = abs((long long)dividend), n = abs((long long)divisor);
        if(n == 1) return (sign==-1) ? -m : m;
        long long res = 0;

        while(m >= n){
            long long t = n, p = 1;
            while(m >= t){
                t <<= 1;
                p <<= 1;
            }
            p >>= 1;
            t >>= 1;
            res += p;
            m -= t;
        }

        return (sign == -1) ? (-res) : res;
    }
};

int main(){
    int dividend = -2147483648, divisor = -1;
    Solution S;
    cout<<S.divide(dividend, divisor)<<endl;

    system("pause");
    return 0;
}