/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* curr = head;
        while(curr != NULL) {
            if(curr->val == -9999999) return true;
            curr->val = -9999999;
            curr = curr->next;
        }
        return false;
    }
};
