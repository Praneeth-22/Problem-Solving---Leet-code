// 70. Climbing Stairs
// Solved
// Easy
// Topics
// Companies
// Hint
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

class Solution {
public:
    int func(int n){
        if(n==0) return 0;
        if( n==1) return 1;
        if(n==2)return 2;
        return func(n-1)+func(n-2);
    }
    int topButtom(int n,vector<int> &dp){
        if(n==0) return dp[0];
        if( n==1) return dp[1];
        if(n==2)return dp[2];
        dp[n] = topButtom(n-1,dp) + topButtom(n-2,dp);
        return dp[n];
        
    }
    int climbStairs(int n) {
        //recursion : O(2 ^n), O(n) 
        // return func(n);
        //Top-Buttom Approach
        if(n==1) return 1;
        vector<int> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        // return topButtom(n,dp);
        //Buttom-Up approach
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};