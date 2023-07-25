// Problem Statement:

// Given an array of ‘N’  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

// Note: A subsequence of an array is a list with elements of the array where some elements are deleted ( or not deleted at all) 
// and the elements should be in the same order in the subsequence as in the array.

import java.io.*;
import java.util.*;

class MaxSumNonAdj {
    public static int FindSum(int[] arr, int n, int[] dp) {
        if (n < 0)
            return 0;
        if (n == 0)
            return arr[n];

        if (dp[n] != -1)
            return dp[n];
        int pick = arr[n] + FindSum(arr, n - 2, dp);
        int notPick = 0 + FindSum(arr, n - 1, dp);

        return dp[n] = Math.max(pick, notPick);

    }

    public static void main(String[] args) {
        int[] arr = { 2, 1, 4, 9 };
        int n = arr.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        System.out.println(FindSum(arr, n - 1, dp));
        Arrays.fill(dp, -1);

        dp[0] = arr[0];
        for (int i = 1; i < n; i++) {
            int pick = arr[i];
            if (i > 1)
                pick += dp[i - 2];
            int notPick = 0 + dp[i - 1];
            dp[i] = Math.max(notPick, pick);

        }
        System.out.println(dp[n - 1]);
    }
}