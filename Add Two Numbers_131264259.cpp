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
        int hand = 0;
        
        ListNode* sum = NULL;
        ListNode* ret = NULL;
        
        while(l1 != NULL && l2 != NULL) {
            int curr = (l1 -> val) + (l2 -> val) + hand;
            
            //cout << (l1 -> val) << " " << (l2 -> val) << " " << hand << endl;
            
            hand = (curr / 10) > 0;
            curr = curr % 10;
            
            if(sum == NULL) {
                sum = new ListNode(curr);
                ret = sum;
            }
            else {
                sum->next = new ListNode(curr);
                sum = sum->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode* unfinished = (l2 == NULL) ? l1 : l2;
        
        while(unfinished != NULL) {
            int curr = (unfinished -> val) + hand;
            
            hand = (curr / 10) > 0;
            curr = (hand > 0) ? 0 : curr;
            
            if(sum == NULL) {
                sum = new ListNode(curr);
                ret = sum;
            }
            else {
                sum->next = new ListNode(curr);
                sum = sum->next;
            }
            
            unfinished = unfinished->next;
        }
        
        if(hand) {
            sum ->next = new ListNode(hand);
            sum = sum ->next;
        }
            
        sum->next = NULL;
        
        return ret;
    }
};
