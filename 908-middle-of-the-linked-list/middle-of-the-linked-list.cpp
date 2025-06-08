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
    ListNode* middleNode(ListNode* head) {
        int count  = 0 ; 
        if ( head == nullptr)
        return head;
        ListNode* temp = head;
        while ( temp )
        {
            count++;
            temp = temp->next;
        }
        int k= count/2;
        count=0;
        temp = head;
        while( count != k)
        {
           count++;
           temp = temp->next;
        }
        return temp;
    }
};