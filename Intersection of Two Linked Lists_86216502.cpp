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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        int f = 0;
        int s = 0;
        ListNode* curr = headA;
        while(curr != NULL) curr = curr -> next, f++;
        curr = headB;
        while(curr != NULL) curr = curr -> next, s++;
        ListNode* res;
        if(f > s) {
            int d = f - s;
            ListNode* a = headA;
            ListNode* b = headB;
            while(d--) a = a -> next;
            res = NULL;
            while(s--) {
                //cout << (a -> val) << " " << (b -> val) << endl;
                if(a -> val == b -> val) {
                    if(res == NULL) {
                        res = a;
                    }
                }
                else {
                    res = NULL;
                }
                a = a -> next;
                b = b -> next;
            }
        }
        else {
            int d = s - f;
            ListNode* a = headA;
            ListNode* b = headB;
            while(d--) b = b -> next;
            res = NULL;
            while(f--) {
                //cout << (a -> val) << " " << (b -> val) << endl;
                if(a -> val == b -> val) {
                    if(res == NULL) {
                        res = a;
                    }
                }
                else {
                    res = NULL;
                }
                a = a -> next;
                b = b -> next;
            }
        }
        return res;
    }
};
