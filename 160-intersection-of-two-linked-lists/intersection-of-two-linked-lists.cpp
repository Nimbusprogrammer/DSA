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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2  =headB;
        int n = 0;
        int m = 0;
        while ( p1)
        {
            n++;
            p1=p1->next;
        }
        while ( p2)
        {
            m++;
            p2=p2->next;
        }
      int need = abs(m-n);
      p1= headA;
      p2 =headB;
      if ( m>n)
      {
        while ( need)
        {
            need--;
            p2= p2->next;
        }
      }
      else 
      {while ( need)
        {
            need--;
            p1= p1->next;
        }
      }
      while ( p1 != p2)
      {
        p1= p1->next;
        p2=p2->next;
      }
      if ( p1 == p2 && p1 != nullptr)
      {
        return p1;

      }
      else 
      return nullptr;


    }
};