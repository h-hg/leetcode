#include <set>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while(fast != nullptr && ( fast = fast -> next ) != nullptr ) {
      fast = fast -> next;
      slow = slow -> next;
      if(fast == slow)
        break;
    }
    if(fast == nullptr)
      return nullptr;
    slow = head;
    while(slow != fast) {
      slow = slow -> next;
      fast = fast -> next;
    }
    return slow;
  }
};