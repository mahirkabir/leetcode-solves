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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* curr = head;
        while(curr != NULL) {curr = curr -> next; sz++;}
        if(sz == n && sz <= 1) return NULL;
        else if(sz == n) {
            head = head -> next;
            return head;
        }
        sz -= n;
        curr = head;
        while(--sz) curr = curr -> next;
        curr -> next = curr -> next -> next;
        return head;
    }
};
