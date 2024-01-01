import java.io.*;
import java.util.*;

class FrogJump {
    public static int frogJump(int[] h, int[] dp, int n) {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int left = frogJump(h, dp, n - 1) + Math.abs(h[n] - h[n - 1]);
        int right = Integer.MAX_VALUE;
        if (n > 1)
            right = frogJump(h, dp, n - 2) + Math.abs(h[n] - h[n - 2]);
        return dp[n] = Math.min(left, right);
    }

    public static void main(String[] args) {
        int n = 4;
        int[] h = new int[] { 10, 20, 30, 10 };
        // memorization
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        System.out.println(frogJump(h, dp, n - 1));

        // Tabulation
        Arrays.fill(dp, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int right = Integer.MAX_VALUE;
            int left = dp[i - 1] + Math.abs(h[i] - h[i - 1]);
            if (i > 1) {
                right = dp[i - 2] + Math.abs(h[i] - h[i - 2]);
            }
            dp[i] = Math.min(left, right);
        }
        System.out.println(dp[n - 1]);

        // Memory optimization
        int prev2 = 0, prev = 0;
        for (int i = 1; i < n; i++) {
            int right = Integer.MAX_VALUE;
            int left = prev + Math.abs(h[i] - h[i - 1]);
            if (i > 1) {
                right = prev2 + Math.abs(h[i] - h[i - 2]);
            }
            int curr = Math.min(left, right);
            prev2 = prev;
            prev = curr;
        }
        System.out.println(prev);
    }
}