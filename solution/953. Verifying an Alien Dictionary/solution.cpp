class Solution {
public:
    bool isAlienSorted(std::vector<std::string>& words, std::string &order) {
    	//init the orders
    	std::vector<int> orders(128,0);
    	for(int i = 0;i < order.size();++i)
    		orders[order[i]] = i;
    	//cmp function
    	auto cmp = [&orders](const std::string &x, const std::string &y){
    		auto first1 = x.begin(), first2 = y.begin();
    		while(first1 != x.end() && first2 != y.end()) {
    			if(orders[*first1] < orders[*first2])
    				return true;
    			else if(orders[*first1] > orders[*first2])
    				return false;
                ++first1;
                ++first2;
    		}
    		return first1 == x.end();

    	};
    	for(int i = 1;i < words.size();++i)
    		if(cmp(words[i-1], words[i]) == false)
    			return false;
    	return true;    
    }
};