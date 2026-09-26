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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ans=head;
        int c=0;
        while(l1 && l2){
            int sum = l1->val + l2->val + c;
            int d = sum%10;
            c=sum/10;
            
            ListNode* node = new ListNode(d);
            head->next=node;
            head=head->next;
            l1=l1->next;
            l2=l2->next;
        }

        while(l1){
            int sum = l1->val + c;
            int d = sum%10;
            c=sum/10;
            
            ListNode* node = new ListNode(d);
            head->next=node;
            head=head->next;
            l1=l1->next;
            
        }
        while(l2){
            int sum = l2->val + c;
            int d = sum%10;
            c=sum/10;
            
            ListNode* node = new ListNode(d);
            head->next=node;
            head=head->next;
            l2=l2->next;
            
        }
        if(c==1){
            ListNode* node = new ListNode(1);
            head->next=node;
            head=head->next;
        }

        return ans->next;
    }
};
