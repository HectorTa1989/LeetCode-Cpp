/*Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.*/

//backtracking solution without extra data structure
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (search(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    
    bool search(vector<vector<char>>& board, string word, int i, int j, int pos) {
        
        if (pos == word.size()) return true;
        if ((i<0) || (i >= board.size()) || (j <0) || (j >= board[i].size())) return false;
        char c = board[i][j];
        if (c == word[pos]) {
            board[i][j] = '#';
            if (search(board, word, i - 1, j, pos + 1)) return true;
            if (search(board, word, i+1, j, pos+1)) return true;
            if (search(board, word, i, j-1, pos+1)) return true;
            if (search(board, word, i, j+1, pos+1)) return true;
            board[i][j] = c;
        }
        return false;
        
    }
};

//DFS
class Solution {
pulic:
bool exist(vector<vector<char>>& board, string word) 
{
		if(board.empty())
			return false;
    
		for(int i=0; i<board.size(); i++)
		{
			for(int j=0; j<board[0].size(); j++)
			{
				if(dfs(board, 0, i, j, word))
					return true;
			}
		}
    
    return false;
}

bool dfs(vector<vector<char>>&board, int count, int i, int j, string& word)
{
    if(word.size() == count) //Signifies that we have reached the end of search
        return true;
    
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[count])
	return false;
    //We check if element is within bounds and then check if the character at that is the same as the corresponding character in string word
        

    char temp = board[i][j];
    board[i][j] = ' '; //To show that we have visited this node
    
    bool res = dfs(board, count+1, i+1, j, word) || dfs(board, count+1, i-1, j, word) || dfs(board, count+1, i, j+1, word) ||dfs(board, count+1, i, j-1, word); //DFS in all 4 directions
    
    board[i][j] = temp; //Restore the element after checking
    
    return res;
}
};
//DFS 2
bool exist(vector<vector<char>>& board, string word) {
    for (unsigned int i = 0; i < board.size(); i++) 
        for (unsigned int j = 0; j < board[0].size(); j++) 
            if (dfs(board, i, j, word))
                return true;
    return false;
}

bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
    if (!word.size())
        return true;
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
        return false;
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
    board[i][j] = c;
    return ret;
}

//backtrack solutions
Solution 1

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0|| word.size() == 0) return true;
        bool find = false;
        vector<vector<int>>visited(board.size(), vector<int>(board[0].size(),0));
        for(int i = 0 ; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                     find = backtrack(i, j, board, word, visited);
                     if(find) return find;
                }
            }
        return find;
    }
    
    bool backtrack(int i, int j, vector<vector<char>>& board, string word, vector<vector<int>>& visited){
        if(word.size() == 0) return true;
        if(i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1) return false;
        if(visited[i][j]) return false;
        bool find = false;
        if(board[i][j] == word[0]){
            word.erase(word.begin());
            visited[i][j] = 1;
            find = backtrack(i-1,j,board,word,visited) || backtrack(i,j-1,board,word,visited) 
                || backtrack(i+1,j,board,word,visited) || backtrack(i,j+1,board,word,visited);
            visited[i][j] = 0;
        }
       return find;
    }
};
Update(8/12/2017):

Solution 2

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        bool found = false;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]) backtrack(board, 1, i, j, m, n, word, found);
                if(found) return true;
            }
        return false;
    }
    
    void backtrack(vector<vector<char>>& board, int pos, int r, int c, int m, int n, string& word, bool& found){
        if(board[r][c] == '0' || found) return;
        if(pos == word.size()){
            found = true;
            return;
        }
        char tmp = board[r][c];
        board[r][c] = '0';
        if(r - 1 >= 0 && board[r - 1][c] == word[pos]) backtrack(board, pos + 1, r - 1, c, m, n, word, found);
        if(r + 1 < m  && board[r + 1][c] == word[pos]) backtrack(board, pos + 1, r + 1, c, m, n, word, found);
        if(c + 1 < n  && board[r][c + 1] == word[pos]) backtrack(board, pos + 1, r, c + 1, m, n, word, found);
        if(c - 1 >= 0 && board[r][c - 1] == word[pos]) backtrack(board, pos + 1, r, c - 1, m, n, word, found);
        board[r][c] = tmp;
    }
};
Update(9/12/2017):

Solution 3.

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == word[0] && BFS(board, i, j, m, n, 0, word)) return true;
        return false;
    }
    
    bool BFS(vector<vector<char>>& board, int r, int c, int m, int n, int len, string& word){
        if(len == word.size()) return true;
        if(r < 0 || c < 0 || r >= m || c >= n || board[r][c] == '#' || board[r][c] != word[len]) return false;
        char tmp = board[r][c];
        board[r][c] = '#';
        bool found =  BFS(board, r + 1, c, m, n, len + 1, word) || BFS(board, r, c + 1, m, n, len + 1, word) ||
                      BFS(board, r - 1, c, m, n, len + 1, word) || BFS(board, r, c - 1, m, n, len + 1, word);
        board[r][c] = tmp;
        return found;
    }
};