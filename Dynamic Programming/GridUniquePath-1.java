import java.io.*;
import java.util.*;

class GridUniquePath {
    public static int Grid(int[][] arr, int row, int col, int[][] dp) {
        if (row < 0 || col < 0)
            return 0;
        if (row == 0 && col == 0)
            return 1;
        if (dp[row][col] != -1)
            return dp[row][col];
        if (row > 0 && col > 0 && arr[row][col] == -1)
            return 0;
        return dp[row][col] = Grid(arr, row - 1, col, dp) + Grid(arr, row, col - 1, dp);
    }

    public static int GridDemo(int[][] arr, int row, int col) {
        int[][] dp = new int[row][col];
        for (int i[] : dp) {
            Arrays.fill(i, -1);
        }
        return Grid(arr, row - 1, col - 1, dp);
    }

    public static void main(String[] args) {
        int[][] arr = new int[][] {
                { 0, 0, 0 }, { 0, -1, 0 }, { 0, 0, 0 }
        };
        int row = arr.length;
        int col = arr[0].length;
        System.out.println(GridDemo(arr, row, col));

        // Tabulation
        int[][] dp = new int[3][3];
        for (int[] i : dp) {
            Arrays.fill(i, -1);
        }

        dp[0][0] = 1;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                if (arr[i][j] == -1) {
                    dp[i][j] = 0;
                    continue;
                }
                int a = 0, b = 0;
                if (i > 0)
                    a = dp[i - 1][j];
                if (j > 0)
                    b = dp[i][j - 1];

                dp[i][j] = a + b;
            }
        }
        System.out.println(dp[row - 1][col - 1]);
        // return dp[row][col] = Grid(arr, row - 1, col, dp) + Grid(arr, row, col - 1,
        // dp);
    }
}