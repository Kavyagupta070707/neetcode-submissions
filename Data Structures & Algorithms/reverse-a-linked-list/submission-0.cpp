/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* nex=head->next;

        while(cur){
            cur->next = prev;
            prev=cur;
            cur=nex;
            if(nex)
            nex=nex->next;
        }
        return prev;
    }
};

    //                 prev cur nex
    //   0     1   2    3  
