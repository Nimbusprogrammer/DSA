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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newhead = new ListNode( 0);
        ListNode* temp = newhead;
        int carry =0;
        while ( l1 && l2)
        {
            int num = l1->val + l2->val;
            int total = carry + num;
            int real = total%10;
            total = total/10;
            carry = total%10;
            temp->next = new ListNode(0);
            temp->next->val = real;
            temp = temp->next;
            l1= l1->next;
            l2= l2->next;
        }
        while ( l1)
        {
            temp->next = new ListNode (0);
            int total  = l1->val + carry;
            int real = total%10;
            total = total/10;
            carry = total%10;
            temp->next->val = real;
            temp = temp->next;
            l1=l1->next;
        }
        while ( l2)
        {
            temp->next = new ListNode (0);
            int total  = l2->val + carry;
            int real = total%10;
            total = total/10;
            carry = total%10;
            temp->next->val = real;
            temp = temp->next;
            l2=l2->next;
        }
        if ( carry )
        {
            temp->next = new ListNode( 0);
            temp->next->val = carry;
        }
        ListNode* ans = newhead->next;
        delete newhead;
        return ans;
    }
};