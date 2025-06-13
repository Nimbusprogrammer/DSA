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
    ListNode* deleteMiddle(ListNode* head) {
        if ( head == nullptr || head ->next == nullptr)
        {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        int key = 0;

        while (fast != nullptr && fast->next != nullptr )
        {
            fast = fast->next->next;
            if ( key ==1 )
            {
                slow = slow->next;
            }
            key =1;
        }
        ListNode* preview = slow->next;
        slow->next = slow->next->next;
        delete preview;
        return head;

    }
};