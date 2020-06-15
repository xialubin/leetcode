#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res_head = new ListNode(0);
        ListNode* res_node = res_head;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        int num1=0, num2=0, c=0;
        while(node1 != NULL || node2 != NULL){
            ListNode* node = new ListNode(0);

            if(node1 != NULL){
                num1 = node1->val;
                node1 = node1->next;
            }
            else 
                num1 = 0;
            
            if(node2 != NULL){
                num2 = node2->val;
                node2 = node2->next;
            }
            else 
                num2 = 0;
            
            int res_num = (num1 + num2 + c) % 10;
            c = (num1 + num2 + c) / 10;
            node->val = res_num;
            res_node->next = node;
            res_node = res_node->next;
        }
        if(c == 1){
            ListNode* node = new ListNode(0);
            node->val = c;
            res_node->next = node;
            res_node = res_node->next;
        }
        return res_head->next;
    }
};

int main(){

}