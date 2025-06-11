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
        vector<int> ans;
        if ( head == nullptr)
        return false;
        ListNode* tail = head;
        ListNode* start = head;
        while ( start )
        {
           ans.push_back(start->val);
           start = start->next;
        }
        vector<int> ans2 = ans;
        reverse(ans2.begin() , ans2.end());
        if ( ans == ans2)
        return true;
        else 
        return false;
    }
};