/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//mantain two pointer of gap n+1
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head;
        for(int i = 0;i <= n;++i) {
        	if(p2 == nullptr)
        		return head -> next;
        	p2 = p2 -> next;
        }
        //if(p2 == nullptr) //remove the head
        	//return head->next;
        while(p2 != nullptr) {
        	p1 = p1 -> next;
        	p2 = p2 -> next;
        }
        //remove the node
        p1 -> next = p1 -> next -> next;
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2 = head;
        for(int i = 0;i < n;++i) {
        	p2 = p2 -> next;
        }
        //make the gap increase 1
        if(p2 == nullptr) //n = number of nodes, remove the head
        	return head->next;
        else
        	p2 = p2 -> next;
        while(p2 != nullptr) {
        	p1 = p1 -> next;
        	p2 = p2 -> next;
        }
        //remove the node
        p1 -> next = p1 -> next -> next;
        return head;
    }
};
//add a new header to aviod that n is equal to the number of nodes
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode header(0);header.next = head;
        ListNode *p1 = &header, *p2 = &header;
        for(int i = 0;i <= n;++i) {
        	p2 = p2 -> next;
        }
        while(p2 != nullptr) {
        	p1 = p1 -> next;
        	p2 = p2 -> next;
        }
        //remove the node
        p1 -> next = p1 -> next -> next;
        return header.next;
    }
};