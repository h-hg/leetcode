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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
        	return l2;
        else if(l2 == nullptr)
        	return l1;
        ListNode *ans, *cur;
        if(l1->val < l2->val) {
        	ans = cur = l1;
        	l1 = l1 -> next;
        } else {
        	ans = cur = l2;
        	l2 = l2 -> next;
        }
        while(l1 != nullptr && l2 != nullptr) {
	        if(l1->val < l2->val) {
	        	cur -> next = l1;
	        	l1 = l1 -> next;
	        } else {
	        	cur -> next = l2;
	        	l2 = l2 -> next;
	        }
            cur = cur -> next;
        }
        cur->next = l1 == nullptr ? l2 : l1;
        return ans;
    }
};