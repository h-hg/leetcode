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
    set<ListNode *> s;
    s.insert(nullptr);
    while(!s.count(head)) {
      s.insert(head);
      head = head -> next;
    }
    return head;
  }
};