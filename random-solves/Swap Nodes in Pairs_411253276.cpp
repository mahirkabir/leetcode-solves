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
    
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        ListNode* res = prev;
        
        while(head != NULL && head->next != NULL) {
            prev->next = head->next;
            head->next = head->next->next;
            prev->next->next = head;
            
            prev = prev->next->next;
            head = prev->next;
        } 
        
        return res->next;
    }
};
