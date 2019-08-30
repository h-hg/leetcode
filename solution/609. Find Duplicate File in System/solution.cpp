class Solution {
public:
    std::vector<std::vector<std::string>> findDuplicate(std::vector<std::string>& paths) {
        std::map< std::string, std::vector<std::string> > content2paths;//content to paths
        for(auto path: paths) {
        	//get the dir
        	int first = 0, last = path.find(' ', first);
        	auto dir = path.substr(first, last - first);
        	//get file name and file content
        	first = last + 1;//skip the space
        	std::string filename, content;
        	while(last = path.find('(', first), last != std::string::npos) {
        		filename = path.substr(first, last - first);
        		first = last + 1;//skip the '('
        		last = path.find(')', first);
        		content = path.substr(first, last-first);
                content2paths[content].push_back(dir+"/"+filename);//insert
        		first = last + 2;//skip the  ") "
        	};
        }
        //remove the path whose content is not repeat. Using std::swap to reduce the cost of memory copy
		std::vector<std::vector<std::string>> ans(content2paths.size());
		int size = -1;
		for(auto &val:content2paths)
			if(val.second.size() > 1)
				std::swap(ans[++size], val.second);
		ans.resize(size+1);
		return ans;
    }
};
