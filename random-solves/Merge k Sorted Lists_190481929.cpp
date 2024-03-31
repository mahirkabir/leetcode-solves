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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = new ListNode(-1);
        ListNode* curr = root;
        
        int n = lists.size();
        while(true) {
            bool hasLeft = false;
            
            int minIdx = -1;
            for(int i = 0; i < n; ++i) {
                if(lists[i] != NULL) {
                    hasLeft = true;
                    
                    if(minIdx == -1 || lists[i]->val < lists[minIdx]->val)
                        minIdx = i;
                }
            }
            
            if(hasLeft) {
                curr->next = new ListNode(lists[minIdx]->val);
                curr = curr->next;
                lists[minIdx] = lists[minIdx]->next;
            }
            else {
                break;
            }
        }
        
        curr->next = NULL;
        root = root->next;
        
        return root;
    }
};
