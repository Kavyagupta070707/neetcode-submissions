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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(!list1&&!list2) return NULL;

        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(cur1 && cur2){
            if(cur1->val<cur2->val){
                cur->next = new ListNode(cur1->val);
                cur1=cur1->next;
                cur=cur->next;
            }
            else{
                cur->next = new ListNode(cur2->val);
                cur2=cur2->next;
                cur=cur->next;
            }
        }

        while(cur1){
            cur->next = new ListNode(cur1->val);
            cur1=cur1->next;
            cur=cur->next;
        }
        while(cur2){
            cur->next = new ListNode(cur2->val);
            cur2=cur2->next;
            cur=cur->next;
        }

        return head->next;
    }
};
