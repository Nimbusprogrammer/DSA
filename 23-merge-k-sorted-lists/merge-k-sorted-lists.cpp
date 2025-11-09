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
 class compare {
    public:
     bool operator()(ListNode*a  , ListNode*b){
        return a->val > b->val; //means high priority to which ever is smaller
        //if true means b ( second passed value here) is high priority 
        //if false then a(first passed value) is high priority.
     }
 };
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //use a minheap to do it .
        
        priority_queue<ListNode* , vector<ListNode*> , compare> pq;
        //compare class automatically dereferences to val and compares and places those nodes in required position
        for( auto list : lists){
            if ( list != NULL)
            pq.push(list);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        while ( !pq.empty()){
            
             ans->next = pq.top();//guard pq.top() : like when pq becomes empty what is pq.top() ? that is why end the code after pq becomes empty
             ans = ans->next;
             pq.pop();
             if (ans->next != NULL)
             pq.push(ans->next);

        }
        return dummy->next;

    }
};