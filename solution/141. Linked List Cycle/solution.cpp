
//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while(fast != nullptr && ( fast = fast -> next ) != nullptr ) {
      fast = fast -> next;
      slow = slow -> next;
      if(fast == slow)
        return true;
    }
    return false;
  }
};