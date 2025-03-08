// 2379. Minimum Recolors to Get K Consecutive Black Blocks
// Solved
// Easy
// Topics
// Companies
// Hint
// You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

// You are also given an integer k, which is the desired number of consecutive black blocks.

// In one operation, you can recolor a white block such that it becomes a black block.

// Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

 

// Example 1:

// Input: blocks = "WBBWWBBWBW", k = 7
// Output: 3
// Explanation:
// One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
// so that blocks = "BBBBBBBWBW". 
// It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
// Therefore, we return 3.
// Example 2:

// Input: blocks = "WBWBBBW", k = 2
// Output: 0
// Explanation:
// No changes need to be made, since 2 consecutive black blocks already exist.
// Therefore, we return 0.
 

// Constraints:

// n == blocks.length
// 1 <= n <= 100
// blocks[i] is either 'W' or 'B'.
// 1 <= k <= n

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // brute force
        //  int cnt = INT_MAX;
        //  for (int i = 0; i <= blocks.size() - k; i++) {
        //      int w_cnt = 0;
        //      for (int j = i; j < i + k; j++) {
        //          if (blocks[j] == 'W')
        //              w_cnt++;
        //      }
        //      cnt = min(cnt, w_cnt);
        //  }

        // return cnt;

        // optimal
        int w_cnt = 0, min_w = INT_MAX;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W')
                w_cnt++;
        }
        min_w = w_cnt;
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W')
                w_cnt++;
            if (blocks[i - k] == 'W')
                w_cnt--;
            min_w = min(min_w, w_cnt);
        }

        return min_w;
    }
};