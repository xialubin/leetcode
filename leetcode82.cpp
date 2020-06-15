#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include "limits.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* node_i = new_head;
        ListNode* node_j = node_i->next;
        if(node_j == NULL) return head;

        int num = INT32_MAX;
        ListNode* temp;
        while(node_j != NULL){
            if(node_j->next != NULL && node_j->val == node_j->next->val){
                num = node_j->val;
                while(node_j != NULL && node_j->val == num){
                    temp = node_j;
                    node_j = node_j->next;
                    temp = NULL;
                }
                node_i->next = node_j;
                continue;
            }
            node_j = node_j->next;
            node_i = node_i->next;
        }

        return new_head->next;
    }
};