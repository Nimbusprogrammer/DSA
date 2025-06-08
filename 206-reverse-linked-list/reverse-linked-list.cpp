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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prevnode = nullptr;
        if (head == nullptr || head->next == nullptr  )
        return head;
        while ( temp-> next != nullptr)
        {
            ListNode * new1 = temp->next;
            temp->next = prevnode;
            prevnode = temp;
            temp = new1;
        }
        temp->next = prevnode;
        return temp;
    }
};