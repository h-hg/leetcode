/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//mine
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry = l1->val + l2->val;
        auto ans = new ListNode(carry % 10),curpos = ans;
        carry /= 10;
        for(l1 = l1->next, l2 = l2->next;l1 != nullptr || l2 != nullptr;) {
        	int l1val = 0, l2val = 0;
        	if(l1 != nullptr) {
        		l1val = l1 -> val;
        		l1 = l1 -> next;
        	}
        	if(l2 != nullptr) {
        		l2val = l2 -> val;
        		l2 = l2 -> next;
        	}
        	carry += l1val + l2val;
        	curpos = curpos -> next = new ListNode(carry % 10);
        	carry /= 10;
        }
        if(carry != 0)
        	curpos->next = new ListNode(carry);
        return ans;
    }
};