// 419. Battleships in a Board
// Solved
// Medium
// Topics
// Companies
// Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

// Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

 

// Example 1:


// Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
// Output: 2
// Example 2:

// Input: board = [["."]]
// Output: 0
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is either '.' or 'X'.
 

// Follow up: Could you do it in one-pass, using only O(1) extra memory and without modifying the values board?

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') {
                    if (i == 0 && j == 0) {
                        res++;
                    } else if (i == 0) {
                        if(board[i][j-1]!='X') res++;
                    } else if (j==0){   
                        if(board[i-1][j]!='X') res++;
                    }else{
                        if(board[i-1][j]!='X' && board[i][j-1]!='X') res++;
                    }
                }
            }
        }
        return res;
    }
};