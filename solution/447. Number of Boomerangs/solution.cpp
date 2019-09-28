class Solution {
private:
	inline int distance(const vector<int> &x, const vector<int> &y) {
		return (x.front()-y.front()) *(x.front()-y.front()) + (x.back()-y.back())*(x.back()-y.back());
	}
public:
    int numberOfBoomerangs(std::vector<vector<int>>& points) {
		int ans = 0;
        std::unordered_map<int,int> d2c;//distance to count
		for(auto &p1:points) {
			d2c.clear();
			for(auto &p2:points)
				if(&p1 != &p2)
					++d2c[distance(p1,p2)];
			for(auto &p:d2c)
	            ans += p.second * (p.second-1); //A(n,2)
		}
		return ans;
    }
};