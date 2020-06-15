#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include "limits.h"


 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //设定反转开始点（反转开始点是第一个需要反转的点的前一个节点），
        //从需要反转的点开始，一个一个把节点提上来，连接到反转开始点之后。
        ListNode* new_head = new ListNode(0);
        ListNode* p = new_head;
        ListNode* temp = new_head;
        ListNode* reversestart = new_head;
        ListNode* reverseend = new_head;
        new_head->next = head;

        int ind = 0;
        while(p != NULL){
            temp = p;
            p = p->next;
            if(ind >= m && ind <= n){
                if(ind == m){
                    reverseend = temp;
                    ind++;
                    continue;
                }
                reverseend->next = temp->next;
                temp->next = reversestart->next;
                reversestart->next = temp;
            }
            if(ind < (m - 1))
                reversestart = reversestart->next;
            ind++;
        }

        head = new_head->next;
        delete new_head;

        return head;
    }
};