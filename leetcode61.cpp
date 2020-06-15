#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return head;
        int len = 0;
        ListNode *num = new ListNode(0);
        num->next = head;
        while(num->next!=NULL){
            num = num->next;
            len ++;
        }
        cout<<len<<endl;
        k = k % len;
        if(k == 0)
            return head;
        ListNode *left = new ListNode(0);
        left->next = head;
        ListNode *right = left;
        for(int i=0 ;i<k; i++){
            if(right->next == NULL){
                right = left;
                i --;
            }
            else
                right = right->next;
            //cout<<right->val<<endl;
        }
        while(right->next != NULL){
            left = left->next;
            right = right->next;
        }
        ListNode *new_head = left->next;
        right->next = head;
        left->next = NULL;
        return new_head;
    }
};