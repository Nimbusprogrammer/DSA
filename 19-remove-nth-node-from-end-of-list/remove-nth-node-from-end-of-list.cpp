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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        if ( head->next == nullptr)
        return nullptr;
        for  ( int i = 0 ; i < n ; i++)
        {
            fast = fast->next;

        }
        if ( fast == nullptr)
        {
            head = head->next;
            slow->next = nullptr;
            delete slow;
            return head;
        }
        while ( fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;

        }
        
        ListNode* newp = slow->next;
        slow ->next = slow ->next ->next;
        delete newp;
        return head;
    }
};