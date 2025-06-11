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
    ListNode *detectCycle(ListNode *head) {
        //using floyds algorithm-> x+y = nc
        //first detect the loop and then x+y = nc formulae based use it to keep slow at start again and make both fast and slow to go 1 step at a time.
        ListNode * slow = head;
        ListNode* fast =  head;
        while( fast != nullptr && fast->next != nullptr )
        {
            slow = slow->next;
            fast= fast->next->next;
            if ( slow == fast)
            {
                //loop exists
                slow = head;
                while( slow != fast)//means while loop stops when the both are equal.
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};