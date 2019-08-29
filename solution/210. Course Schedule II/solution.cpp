#include <vector>
//topological sorting - delete the sort
class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        //init the adacency list
        std::map<int, std::vector<int>> graph;
        std::vector<int> indegrees(numCourses, 0);
        for(auto &val:prerequisites) {
            graph[val[1]].push_back(val[0]);
            ++indegrees[val[0]];
        }
        std::vector<int> ans;
        ans.reserve(numCourses);
        //topological sorting   
        while(graph.size()) {
            //find a node having indegree 0
            int id = -1;
            for(auto &val:graph)
                if(indegrees[val.first] == 0) {
                    id = val.first;
                    break;
                }
            if(id == -1)//graph.size() != 0 and there is no such node
                return std::vector<int>();
            indegrees[id] = -1;//a tag means that this node has been visited and inserted to ans
            //delete the source
            for(auto neighbor:graph[id])
                --indegrees[neighbor];
            graph.erase(id);
            ans.push_back(id);
        }
        for(int id = 0;id < numCourses;++id)
            if(indegrees[id] == 0)
                ans.push_back(id);
        return ans;
    }
}; 


//topological sorting - bfs
class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        //init the adacency list
        std::vector<std::vector<int>> graph(numCourses);
        std::vector<int> indegrees(numCourses, 0);
        for(auto &val:prerequisites) {
            graph[val[1]].push_back(val[0]);
            ++indegrees[val[0]];
        }
        //bfs
        std::vector<int> ans; ans.reserve(numCourses);
        std::queue<int> q;//q is a queue
        for(int id = 0; id < numCourses;++id)//find the nodes with indegree 0
            if(indegrees[id] == 0)
                q.push(id);
        while(q.size()) {
            for(int i = 0, n = q.size();i < n;++i) {
                int id = q.front();
                q.pop();
                ans.push_back(id);
                for(auto child:graph[id])
                    if(--indegrees[child] == 0)//only push when the indegree is 0
                        q.push(child);
            }
        }
        return ans.size() == numCourses ? ans : std::vector<int>();
    }
};