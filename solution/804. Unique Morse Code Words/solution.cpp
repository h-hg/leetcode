#include <vector>
#include <string>
#include <set>
class Solution {
private:
	const std::vector<std::string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words) {
        std::set<std::string> s;
        std::string MorseCode; 
        for(auto &word:words) {
        	MorseCode.clear();
        	for(auto c:word)
        		MorseCode.append(table[c-'a']);
        	s.insert(MorseCode);
        }
        return s.size();
    }
};