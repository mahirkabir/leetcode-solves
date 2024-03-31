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
    void print(ListNode* head) {
        ListNode* p = head;
        while(p != NULL) {
            cout << (p->val) << " ";
            p = p->next;
        }
        cout << endl;
        return;
    }
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return 
            head;
        
        ListNode* oddLast = head;
        ListNode* evenFirst = head->next;
        ListNode* evenLast = head->next;
        
        while(true) {
            oddLast->next = evenLast->next;
            evenLast->next = evenLast->next->next;
            oddLast->next->next = evenFirst;
            oddLast = oddLast->next;
            evenLast = evenLast->next;
            if(evenLast == NULL || evenLast->next == NULL) break;
            //print(head);
        }
        
        return head;
    }
};
