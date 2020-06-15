#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "math.h"

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int res;
        res = int(sqrt(double(x)));
        return res;
    }
};

int main(){
    int a = 12;
    Solution S;
    int b = S.mySqrt(a);
    cout<<b<<endl;

    system("pause");
    return 0;
}
