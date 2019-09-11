#include <vector>
#include <string>
class Solution {
public:
	Solution() {
    	std::ios::sync_with_stdio(false);
    	std::cin.tie(nullptr);
	}
    bool isValid(std::string &S) {
        std::string st;//st is structure similar to stack
        st.reserve(S.size());
        for(auto c:S)
        	if(c == 'c' && st.size() >= 2 && st.back() == 'b' && st[st.size() -2] == 'a') {
        		st.pop_back();
        		st.pop_back();
        	} else
        		st.push_back(c);
        return st.empty();
    }
};

class Solution {
public:
  Solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  }
  bool isValid(string S) {    
    // Algorithm: push to stack, removing "abc" sequences along the way.
    // The removal is triggered by a "c" push operation.
    // Once you reach the end, it must be empty for any valid sequence
    // (including empty one)
    std::stack<char> st;
    for (auto c : S) {
      if (c == 'c' && !st.empty() && st.top() == 'b') {
        // check if after removing top ("b") we find "a"
        st.pop();
        if (!st.empty() && st.top() == 'a')
          st.pop(); // removed "abc" subsequence
        else {
          // out of luck, top is not "a"
          st.push('b'); 
          st.push('c');                  
        }
      } else
        // "a" or "b" case
        st.push(c);
    }
    return st.empty();
  }
};