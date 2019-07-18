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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);dummy.next = head;
        ListNode *p1 = &dummy,*p2 = head;

        while(p2 != nullptr && p2->next != nullptr) {
        	//swap p1->next and p2->next, 0(p1) -> 1(p2) -> 2 -> 3
        	p1->next = p2->next;
        	/*   ______________
        	    |              v
				0(p1) 1(p2) -> 2 -> 3
        	*/
        	p2->next = p2->next->next;
        	/*   ______________
        	    |              v
				0(p1) 1(p2) -> 2 -> 3
				      |             ^
				      ---------------    
        	*/
        	p1->next->next = p2;
        	//0(p1) -> 2(p2) -> 1 -> 3
        	//move farword
        	p1 = p1 -> next -> next;
        	p2 = p1 -> next;
        	//0 -> 2(p1) -> 1(p2) -> 3
        }
        return dummy.next;
    }
};