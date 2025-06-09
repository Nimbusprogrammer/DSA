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
    bool hasCycle(ListNode *head) {
        unordered_set <ListNode*> contain;
        if ( head == nullptr )
        return false;
        while ( head )
        {
            if ( contain.find( head ) == contain.end())
            {
                contain.insert(head);
                head = head->next;
            }
            else 
            return true;
        }
        return false;
    }
};