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
    /*void print(ListNode* p) {
        while(p != NULL) {
            cout << (p->val) << " ";
            p = p->next;
        }
        cout << endl;
    }*/
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *ret;
        ret = ans;
        
        while(l1 != NULL || l2 != NULL) {
            if(l1 != NULL && l2 != NULL) {
                if(l1->val <= l2->val) {
                    ans->next = new ListNode(l1->val);
                    ans = ans->next;
                    l1 = l1->next;
                } 
                else {
                    ans->next = new ListNode(l2->val);
                    ans = ans->next;
                    l2= l2->next;
                }
            }
            else if(l1 != NULL) {
                ans->next = new ListNode(l1->val);
                ans = ans->next;
                l1 = l1->next;
            }
            else {
                ans->next = new ListNode(l2->val);
                ans = ans->next;
                l2 = l2->next;
            }
        }
        ret = ret->next;
        
        return ret;
    }
};
