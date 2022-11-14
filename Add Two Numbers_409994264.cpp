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
        ListNode* res = new ListNode();
        ListNode* p = res;
        ListNode* prev = res;
        
        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            int num = l1->val + l2->val + carry;
            carry = 0;
            if(num >= 10) {
                num = num - 10;
                carry = 1;
            }
            
            p->val = num;
            p->next = new ListNode();
            prev = p;
            p = p->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL) {
            int num = l1->val + carry;
            carry = 0;
            if(num >= 10) {
                num = num - 10;
                carry = 1;
            }
            
            p->val = num;
            p->next = new ListNode();
            prev = p;
            p = p->next;
            
            l1 = l1->next;
        }
        
        while(l2 != NULL) {
            int num = l2->val + carry;
            carry = 0;
            if(num >= 10) {
                num = num - 10;
                carry = 1;
            }
            
            p->val = num;
            p->next = new ListNode();
            prev = p;
            p = p->next;
            
            l2 = l2->next;
        }
        
        if(carry > 0) {
            p->val = carry;
            p->next = NULL;
        }
        else {
            prev->next = NULL;
        }
        
        return res;
    }
};
