// 79. Word Search
// Solved
// Medium
// Topics
// Companies
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 

// Follow up: Could you use search pruning to make your solution faster with a larger board?


class Solution {
public:
    bool findWord(vector<vector<char>>& board, string& word, int row, int col, int index, vector<vector<bool>>& visited) {
        if (index == word.length()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            visited[row][col] || board[row][col] != word[index]) {
            return false;
        }
        visited[row][col] = true;
        bool found = findWord(board, word, row + 1, col, index + 1, visited) || 
                     findWord(board, word, row - 1, col, index + 1, visited) ||
                     findWord(board, word, row, col + 1, index + 1, visited) || 
                     findWord(board, word, row, col - 1, index + 1, visited);  

        // Backtrack: Unmark the current cell as visited before returning
        // This is crucial for exploring other paths that might use this cell later
        visited[row][col] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (findWord(board, word, i, j, 0, visited)) 
                        return true; 

                }
            }
        }
        return false; 
    }
};