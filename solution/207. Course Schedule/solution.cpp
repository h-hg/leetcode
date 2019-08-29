#include <vector>

//dfs
class Solution {
    bool detect(const std::vector<std::vector<int>> &graph, int curId, std::vector<bool> &curPath){
        if(curPath[curId])//avoid re-checking the nodes visited in previous paths; 
            return false;
        curPath[curId] = true;//should be labelled as visited for the current path
        for(auto neighbor:graph[curId])
            if( detect(graph, neighbor, curPath) == false )
                return false;
        curPath[curId] = false;//restored to its unvisited state for another branch of the same starting node;
        return true;
    }
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        //init the adjacency list
        std::vector<std::vector<int>> graph(numCourses);
        for(auto &val:prerequisites)
            graph[val[1]].push_back(val[0]);
        //detect
        std::vector<bool> curPath(numCourses, false);//a record of nodes in current path that we have visited
        for(int i = 0;i < numCourses; ++i)//i is an id
            if(detect(graph, i, curPath) == false)
                return false;
        return true;
    }
};

//improve the solution above, avoid visited the nodes which have been visited
class Solution {
    //detect whether there is a circle, 0 = circle, 1 = no circle, -1 = the node has been visited
    int detect(const std::vector<std::vector<int>> &graph, int curId, std::vector<bool> &visited, std::vector<bool> &curPath){
        if(curPath[curId])//avoid re-checking the nodes visited in previous paths; 
            return 0;
        if(visited[curId])//this node has been visited
            return -1;
        visited[curId] = true;//each node visited should be labelled as visited avoiding further checking;
        curPath[curId] = true;//should be labelled as visited for the current path
        for(auto neighbor:graph[curId])
            if( detect(graph, neighbor, visited, curPath) == 0 )
                return 0;
        curPath[curId] = false;//restored to its unvisited state for another branch of the same starting node;
        return 1;
    }
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        //init the adjacency list
        std::vector<std::vector<int>> graph(numCourses);
        for(auto &val:prerequisites)
            graph[val[1]].push_back(val[0]);
        //detect
        std::vector<bool> visited(numCourses, false), //a record of nodes that we have visited
                          curPath(numCourses,false);  //a record of nodes in current path that we have visited
        
        for(int i = 0;i < numCourses; ++i)//i is an id
            if(visited[i] == false)//avoid re-checking the nodes visited
                if(detect(graph, i, visited, curPath) == 0)
                    return false;
        return true;
    }
};




//topological sorting method - delete sthe source
class Solution {
public:
    inline bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        //init the adjacency list
        std::map<int, std::vector<int>> graph;
        std::vector<int> indegrees(numCourses, 0);
        for(auto &val:prerequisites) {
            graph[val[1]].push_back(val[0]);
            ++indegrees[val[0]];
        }
        //topological sorting      
        while(graph.size()) {
            //find a node having indegree 0
            int id = -1;
            for(auto &val:graph)
                if(indegrees[val.first] == 0)
                    id = val.first;
            if(id == -1)//graph.size() != 0 and there is no such node
                return false;
            //delete the source
            for(auto neighbor:graph[id])
                --indegrees[neighbor];
            graph.erase(id);
        }
        return true;
    }
};