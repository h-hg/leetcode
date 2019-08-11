class Solution {
private:
    int row = 0, col = 0;
    bool dfs(std::string::iterator iter, std::string::iterator last, std::vector<std::vector<char>>& board, int i, int j)
    {
        //judge end
        if(iter == last)
        	return true;
        //judge border
        if(i < 0 || row <= i || j < 0 || col <= j || board[i][j] != *iter)
            return false;
        ++iter;
        auto oldval = board[i][j];
        board[i][j] = '\0';//a tag to record the position you have run
        auto ret = dfs(iter, last, board, i - 1, j) || dfs(iter, last, board, i + 1, j) || dfs(iter, last, board, i, j-1) || dfs(iter, last, board, i, j+1);
        board[i][j] = oldval;//backtracing
        return ret;
    }
        
public:
    bool exist(std::vector<std::vector<char>>& board, std::string &word) {
        row = board.size();
        col = board.front().size();
        for(int i = 0; i < row;++i)
        	for(int j = 0; j < col;++j)
        		if( dfs(word.begin(), word.end(), board, i, j) )
        			return true;
        return false;
    }
};

//Don't write code like the following, it will lead to infinite recursion
/*class Solution {
private:
    int row = 0, col = 0;
    bool dfs(std::string::iterator iter, std::string::iterator last, std::vector<std::vector<char>>& board, int i, int j)
    {
        //judge end
        if(iter == last)
            return true;
        //judge border
        if(i < 0 || row <= i || j < 0 || col <= j)
            return false;
        if( board[i][j] != *iter ) {
            return dfs(iter, last, board, i - 1, j) || dfs(iter, last, board, i + 1, j) || dfs(iter, last, board, i, j - 1) || dfs(iter, last, board, i, j + 1);
        } else {
            ++iter;
            auto oldval = board[i][j];
            auto ret = dfs(iter, last, board, i - 1, j) || dfs(iter, last, board, i + 1, j) || dfs(iter, last, board, i, j-1) || dfs(iter, last, board, i, j+1);
            board[i][j] = oldval;
            return ret;
        }
    }
        
public:
    bool exist(std::vector<std::vector<char>>& board, std::string &word) {
        row = board.size();
        col = board.front().size();
        return dfs(word.begin(), word.end(), board, 0, 0);
    }
};*/