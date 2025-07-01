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
    ListNode* rotateRight(ListNode* head, int k) {
           ListNode* temp = head;
           if ( head == nullptr || head->next == nullptr)
           {
            return head;
           }
           int n = 0; 
           while ( temp )
           {
               n+=1;
                temp =temp->next;
           }
           if ( k >=n )
           {
            k %= n;
           }
           if ( k == 0)
           return head;
           int req = n-k;
           temp = head;
           req-=1;
           while ( req--)
           {
               temp = temp->next;

           }
           ListNode* after = temp->next;
           temp->next = nullptr;
           ListNode* exp = after ;
           while ( exp->next != nullptr )
           {
              exp = exp->next;
           }
           exp->next = head;
           head = after ;
           return head;
    }
};