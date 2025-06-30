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
ListNode* givekthelem (ListNode* temp , int k)
{
    k -=1;
    while ( k-- && temp != nullptr)
    {
        temp = temp->next;
        
    }
    return temp;
}
ListNode* reverse( ListNode* temp)
{
    ListNode* prev = nullptr;
    ListNode* after = nullptr;
    while( temp )
    {
      after = temp->next;
      temp->next = prev;
      prev = temp;
      temp = after; 
    }
    return prev;
}

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* previous = nullptr;
        while ( temp )
        {
            ListNode* kthnode = givekthelem( temp , k);
            if ( kthnode == nullptr)
            {
                   if( previous )
                   {
                    previous ->next = temp;
                   }
                   break;
            }
            else 
            {
                ListNode* after = kthnode->next;
                kthnode->next = nullptr;
                reverse( temp );
                
                //we changed temp values in reversepart function it is passed by value not reference , so here temp still points to old temp .
                if ( temp == head)
                head = kthnode;
                else
                {
                previous->next = kthnode;
                }
                previous = temp;
                temp = after ;

            }
        }
        return head;
    }
};