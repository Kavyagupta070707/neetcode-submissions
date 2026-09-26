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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* head2 = new ListNode(0);
        head2->next=head;
        ListNode* left = head2;
        ListNode* right = head;

        while(n>0){
            right=right->next;
            n--;
        }

        while(right){
            left=left->next;
            right=right->next;
        }

        left->next=left->next->next;

        return head2->next;
    }
};
