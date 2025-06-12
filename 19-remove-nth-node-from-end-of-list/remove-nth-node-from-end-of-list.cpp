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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if ( head == nullptr)
        return head;
        int totaldig;
        ListNode* fast= head;
        ListNode* slow = head;
        int count = 0;
        while( fast != nullptr && fast->next != nullptr)
       {
          fast = fast->next ->next;
          slow = slow->next;
          count++;
       }
       slow = head;
        if ( fast == nullptr)
        {
             totaldig = 2* count;
        }
        else
         totaldig = 2*(count)+1;
        count = 1;
        int tofind = totaldig-n+1;
        if ( tofind==1)
        {
            head = head->next;
            slow->next = nullptr;
            delete slow;
            return head;
        }
        while ( count != (tofind-1))
        {
           slow = slow->next;
           count++;
        }
        slow->next = slow->next ->next;
        return head;
    }
};