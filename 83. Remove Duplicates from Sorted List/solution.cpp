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
    ListNode* deleteDuplicates(ListNode* head) {
   		if(head == nullptr)
   			return nullptr;
   		int lastval = head -> val;
   		for(auto pre = head, cur = pre->next;cur != nullptr;) {
   			if(cur -> val == lastval) {
   				cur = pre -> next = cur -> next;
   			} else{
   				lastval = cur -> val;
   				pre = cur;
   				cur = cur -> next;
   			}
   		}
   		return head;
    }
};