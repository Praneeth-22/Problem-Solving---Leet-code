import java.io.*;
import java.util.*;
public class MinMaxFallPathSum {
    public static int getPath(int [][] arr,int row,int j,int col,int [][] dp){
        if(j<0 || j>=col ) return (int)Math.pow(-10,9);
        if(row==0) return arr[0][j];
        if(dp[row][j]!=-1) return dp[row][j];
        int up = arr[row][j] + getPath(arr, row-1, j, col, dp);
        int left = arr[row][j] + getPath(arr, row-1, j-1, col, dp);
        int right = arr[row][j] + getPath(arr, row-1, j+1, col, dp);
        return dp[row][j] = Math.max(up,Math.max(left,right));
    }
    public static int find(int [][] m){
        int row = m.length;
        int col = m[0].length;
        int dp [][] = new int [row][col];
        for(int i[]:dp){
            Arrays.fill(i,-1);
        }
        int maxx = Integer.MIN_VALUE;
        for(int i=0;i<row;i++){
            int ans = getPath(m,row-1,i,col,dp);
            maxx = Math.max(ans,maxx);
        }
        return maxx;
    }
    public static void main (String[] args){
        int arr [][] = {{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
        System.out.println(find(arr));
    }
}
