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
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
       
       
            ListNode* mock = temp->next;
            temp->val = mock->val;
             temp->next = mock->next;
           delete mock;
        
        
    }
};