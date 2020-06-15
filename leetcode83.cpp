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
        if(head == NULL) return head;
        ListNode* node_i = new_head;
        ListNode* node_j = node_i->next;
        ListNode* temp;

        while(node_j != NULL){
            while(node_j->next != NULL && node_j->val == node_j->next->val){
                temp = node_j;
                node_j = node_j->next;
                delete temp;
            }
            node_i->next = node_j;
            node_i = node_i->next;
            node_j = node_j->next;
        }

        head = new_head->next;
        delete new_head;
        return head;
    }
};