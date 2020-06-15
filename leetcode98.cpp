#include<iostream>
#include<vector>
#include<algorithm>
#include "limits.h"

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
private:
    int maxnum = INT_MIN;
    bool flag = true;
    bool res = true;
    void inorder_out(TreeNode* root){
        if(root == NULL)
            return;
        if(!res)
            return;

        inorder_out(root->left);
        int root_num = root->val;
        if(flag){
            maxnum = root_num;
            flag = false;
        }
        else{
            if(root_num > maxnum)
                maxnum = root_num;
            else {
                res = false;
            }
        }
        inorder_out(root->right);

        return;
    }
public:
    bool isValidBST(TreeNode* root) {
        inorder_out(root);

        return res;
    }
};