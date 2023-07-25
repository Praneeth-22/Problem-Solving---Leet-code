// Problem Link: Ninja Training

// A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. 
// There are merit points associated with performing an activity each day. The same activity can’t be performed on two consecutive days. We need to find the maximum merit points the ninja can attain in N Days.

// We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. 
// Our task is to calculate the maximum number of merit points that the ninja can earn.

import java.io.*;
import java.util.*;

class NinjaTraining {

    public static int ninjaMaxTraining(int [][] points,int [][] dp,int n,int last){
        if(n<0) return 0;
        if(n==0){
            int maxy=points[0][0];
            for(int work =0;work <3;work++){
                if(work != last){
                    maxy = Math.max(maxy,points[0][work]);
                }
            }
            return dp[n][last] = maxy;
        }
        if(dp[n][last] != -1) return dp[n][last];
        int maxy = 0;
        for(int j=0;j<3;j++){
            int curr_max =0;
            if(j!= last){
                curr_max = points[n][j] + ninjaMaxTraining(points, dp, n-1, j);
            }
            maxy= Math.max(maxy, curr_max);
        }
        return dp[n][last] = maxy;
    }
    public static int findPath(int [][] points,int n){
        int [][] dp = new int[n][4];
        for(int [] row:dp){
            Arrays.fill(row,-1);
        }
        return ninjaMaxTraining(points,dp,n-1,3);
    }
    public static void main(String[] args) {
        int[][] points = { { 10, 40, 70 },
                { 20, 50, 80 },
                { 30, 60, 90 } };
        int n = points.length;
        //memorization
        System.out.println(findPath(points,n));
        //tabulation
        
    }
}