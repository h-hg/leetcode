#include <vector>
#include <string>
//brute force
class Solution {
private:
	static bool f(long prev1, long prev2, std::string::iterator iter, std::string::iterator last, std::vector<int> &ans) {
		if(iter == last)
			return true;
        long sum = prev1 + prev2;
        if(sum > INT_MAX)
        	return false;
		auto strsum = std::to_string(sum);
		if(last - iter < strsum.size())
			return false;
		for(auto c:strsum)
			if(*iter++ != c)
				return false;
		ans.push_back(sum);
		return f(prev2, sum, iter, last,ans);
	}
public:
    std::vector<int> splitIntoFibonacci(std::string &S) {
    	std::vector<int> ans;
        for(int i = 1; i < S.size(); ++i) {
        	if(S.front() == '0' && i > 1)
        		break;
        	long prev1 = stol(S.substr(0, i));
        	if(prev1 > INT_MAX)
        		break;
        	for(int j = i + 1; j < S.size(); ++j) {
        		if(S[i] == '0' && j > i + 1)
        			break;
        		long prev2 = stol(S.substr(i, j-i));
        		if(prev2 > INT_MAX)
        			break;
        		ans.clear();
        		ans.push_back(prev1);
        		ans.push_back(prev2);
        		if(f(prev1, prev2, S.begin()+j, S.end(),ans))
        			return ans;
        	}
        }
        return std::vector<int>();
    }
};

//unrecursive
class Solution {
private:
	static bool f(long prev1, long prev2, std::string::iterator iter, std::string::iterator last, std::vector<int> &ans) {
		long sum;
		while(iter != last){
			sum = prev1 + prev2;
	        if(sum > INT_MAX)
	        	return false;
			auto strsum = std::to_string(sum);
			if(last - iter < strsum.size())
				return false;
			for(auto c:strsum)
				if(*iter++ != c)
					return false;
			ans.push_back(sum);
			//next loop
			prev1 = prev2;
			prev2 = sum;
		}
		return true;
	}
public:
    std::vector<int> splitIntoFibonacci(std::string &S) {
    	std::vector<int> ans;
        for(int i = 1; i < S.size(); ++i) {
        	if(S.front() == '0' && i > 1)
        		break;
        	long prev1 = stol(S.substr(0, i));
        	if(prev1 > INT_MAX)
        		break;
        	for(int j = i + 1; j < S.size(); ++j) {
        		if(S[i] == '0' && j > i + 1)
        			break;
        		long prev2 = stol(S.substr(i, j-i));
        		if(prev2 > INT_MAX)
        			break;
        		ans.clear();
        		ans.push_back(prev1);
        		ans.push_back(prev2);
        		if(f(prev1, prev2, S.begin()+j, S.end(),ans))
        			return ans;
        	}
        }
        return std::vector<int>();
    }
};