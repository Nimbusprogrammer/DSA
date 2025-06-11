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
    bool isPalindrome(ListNode* head) {
        //find the middle of the linked list using tortoise & heir method
        if  ( head ->next == nullptr)
        return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* before = head;
        while( fast != nullptr &&  fast->next != nullptr)
        {
            before = slow;
            slow = slow->next;
            fast = fast->next->next;

        }
        before->next = nullptr;
        ListNode* prev = nullptr;
        while ( slow != nullptr)//reversing the second half of the sll
        {
           ListNode* front = slow->next;
           slow->next = prev;
           prev = slow;
           slow = front;
        }
        while ( head != nullptr && prev != nullptr)
        {
            if ( head->val != prev->val )
            return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};