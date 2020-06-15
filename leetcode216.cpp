#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
  private:
    vector<vector<int>> res;
    void myfunc(vector<int> &res_in, int target, int start, int k)
    {
        if (res_in.size() > k)
            return;
        if (target == 0 && res_in.size() == k)
        {
            res.push_back(res_in);
            return;
        }
        if (target < 0)
            return;
        for (int i = start; i <= 9; i++)
        {
            target = target - i;
            res_in.push_back(i);
            myfunc(res_in, target, i + 1, k);
            res_in.pop_back();
            target = target + i;
        }
    }

  public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> res_in;
        myfunc(res_in, n, 1, k);

        return res;
    }
};

int main()
{
    int k, n;
    while (cin >> k >> n)
    {
        Solution S;
        vector<vector<int>> res;
        res = S.combinationSum3(k, n);
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    system("pause");
    return 0;
}