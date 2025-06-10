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
        //O(1) space solution : tortoise and hare logic 
        ListNode* tortoise = head;
        ListNode* hare = head;
        while ( hare != nullptr && hare->next != nullptr )
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if ( tortoise == hare)
            return true;
            
        }
        return false;
    }
};