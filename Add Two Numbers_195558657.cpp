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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return l1;
        ListNode* res = (ListNode*)malloc(sizeof(ListNode));
        ListNode* it = res;
        long long add = 0;
        while(true) {
            if(l1 != NULL) {
                add += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                add += l2->val;
                l2 = l2->next;
            }
            
            if(add >= 10) {
                it->val = add%10;
                add /= 10;
            }
            else {
                it->val = add;
                add = 0;
            }
            
            if(l1 != NULL || l2 != NULL) {
                it->next = (ListNode*)malloc(sizeof(ListNode));
                it = it->next;    
            }
            else {
                if(add > 0) {
                    it->next = (ListNode*)malloc(sizeof(ListNode));
                    it = it->next;
                    it->val = add;
                    add = 0;
                }
                it->next = NULL;
                break;
            }
        }
        
        return res;
    }
};
