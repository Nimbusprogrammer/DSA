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
    ListNode* findmiddle( ListNode* head)//finding mid using tortoise and hare tech
    {
        ListNode* slow = head;
        ListNode* fast  = head->next; 
        
        //it doesn't make any diff it pointing mid in odd no of but in even num of elem then it makes sure slow is on correct pos
        while ( fast != nullptr && fast->next != nullptr)
        {
            slow= slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwosortedLinkedlists ( ListNode* left , ListNode* right)
    {
        ListNode* dummyhead = new ListNode(0);
        ListNode* temp = dummyhead;
        while ( left != nullptr && right != nullptr)
        {
            if ( left->val < right ->val)
            {   
                
                temp->next = left;
                left = left->next;
                
                temp= temp->next;
            }
            else 
           {
             temp->next = right;
            
            right = right->next;
            
             temp = temp->next;
           }
        }
           if ( left)
           temp->next = left;
           else 
           temp->next = right;
           temp =  dummyhead->next;
           dummyhead->next = nullptr;
           delete dummyhead;
           return temp;
       //this won't work because we are changing the pointer pointing to dummyhead ie temp ie we are actually moving our head of sll so we can't trace it back hence this below method is wrong.

     /*ListNode* dummyhead = new ListNode(0);
        ListNode* temp = dummyhead;
        while ( left != nullptr && right != nullptr)
        {
            if ( left->val < right ->val)
            {   
                
                temp = left;
                left = left->next;
                if ( temp->next != nullptr)
                temp= temp->next;
            }
            else 
           {
             temp = right;
            
            right = right->next;
            if ( temp->next != nullptr)
             temp = temp->next;
           }
        }
           if ( left)
           temp->next = left;
           else 
           temp->next = right;
           return dummyhead;   */

    }
    ListNode* sortList(ListNode* head) {
        //using mergesort technique but unlike mergesort where we return nothing here we have to return the Node* pointer .
        if  ( head== nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* mid = findmiddle ( head);
        //now make sure mid->next == nullptr
        ListNode* righthead = mid->next;
        mid->next = nullptr;
        //now we seperated the ll into 2 parts.now merge sort them internally and then send them to mergetwoarrays function
        ListNode* lefthead = sortList(head);
        righthead = sortList(righthead);
        return mergeTwosortedLinkedlists (lefthead, righthead);

    }
};