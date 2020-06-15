#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Command{
    string s;
    TreeNode *root;
    Command(string str, TreeNode* root) : s(str), root(root) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<Command> comd;
        comd.push(Command("go", root));
        while(!comd.empty()){
            Command c = comd.top();
            comd.pop();
            if(c.s == "print")
                res.push_back(c.root->val);
            else{ // c.s == "go"
                if(c.root->right)
                    comd.push(Command("go", c.root->right));
                comd.push(Command("print", c.root));
                if(c.root->left)
                    comd.push(Command("go", c.root->left));
            }
        }
        return res;
    }
};