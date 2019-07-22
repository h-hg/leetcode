class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(head == nullptr || k == 1)
    		return head;
    	std::vector<ListNode*> ptrs;
    	for(auto cur = head;cur != nullptr; cur = cur -> next)
    		ptrs.push_back(cur);
    	if(k > ptrs.size())
    		return head;
    	std::vector<ListNode*> sortedptrs;sortedptrs.reserve(ptrs.size());
    	int index = 0;
    	for(;index + k <= ptrs.size();index += k)
    		for(int end = index + k -1; end >= index;--end)
    			sortedptrs.push_back(ptrs[end]);
    	for(;index < ptrs.size();++index)
    		sortedptrs.push_back(ptrs[index]);
    	for(int i = 1;i < sortedptrs.size();++i)
    		sortedptrs[i-1] -> next = sortedptrs[i];
    	sortedptrs.back() -> next = nullptr;
    	return sortedptrs[0];
    }
};