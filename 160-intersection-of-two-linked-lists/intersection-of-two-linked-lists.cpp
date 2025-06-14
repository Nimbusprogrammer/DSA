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
        unordered_map <ListNode*  , bool > hashmap;
        ListNode * p1 = headA ;
        ListNode* p2 = headB;
        while ( p1 && p2 )
        {
            
            if( hashmap.find(p1) == hashmap.end() )//its not present
            {
                hashmap[p1] = true;
            }
            else 
            return p1;
            if ( hashmap.find(p2) == hashmap.end())
            {
                hashmap[p2]= true;
            }
            else 
            return p2;
            p1= p1->next;
            p2= p2->next;
        }
        while(p1)
        {
            if ( hashmap.find(p1) == hashmap.end())
             {
                hashmap[p1] = true;
            }
            else 
            return p1;
            p1 = p1->next;
        }
        while ( p2)
        {
             if ( hashmap.find(p2) == hashmap.end())
            {
                hashmap[p2]= true;
            }
            else 
            return p2;
            
            p2= p2->next;
        }
        return nullptr;
    }
};