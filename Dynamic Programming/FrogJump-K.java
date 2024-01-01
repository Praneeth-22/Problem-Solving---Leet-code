import java.io.*;
import java.util.*;

class FrogJumpK {
    public static int frogJump(int[] h, int[] dp, int n,int k) {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int steps = Integer.MAX_VALUE;
    
        for(int iter = 1;iter<=k;iter++){
            if(n - iter >=0){

           
            int jump = frogJump(h,dp,n-iter,k) + Math.abs(h[n] - h[n-iter]);
            steps = Math.min(jump,steps);
             }
        }
        return dp[n] = steps;
    }

    public static void main(String[] args) {
        int n = 6;
        int k =2;
        int[] h = new int[] { 30,10,60 , 10 , 60 , 50};
        // memorization
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        System.out.println(frogJump(h, dp, n - 1,k));

        // Tabulation
        Arrays.fill(dp, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int steps = Integer.MAX_VALUE;
            for(int j= 1;j<=k;j++){
                if(i-j>=0){
                    int jump = dp[i-j] + Math.abs(h[i]-h[i-j]);
                    steps = Math.min(jump,steps);
                }
            }
            dp[i] = steps;
        }
        System.out.println(dp[n - 1]);

    }
}