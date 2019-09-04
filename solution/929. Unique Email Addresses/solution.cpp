#include <string>
#include <vector>
#include <set>
class Solution {
public:
    int numUniqueEmails(std::vector<std::string>& emails) {
        std::string stdmail;
        std::set<std::string> s;
        for(auto &email:emails) {
        	stdmail.clear();
        	for(auto iter = email.begin();*iter != '@';++iter)
        		if(*iter == '+')
        			break;
        		else if(*iter != '.')
        			stdmail.push_back(*iter);
        	stdmail.append(email.begin()+email.find('@'), email.end());
        	s.insert(stdmail);
        }
        return s.size();
    }
};