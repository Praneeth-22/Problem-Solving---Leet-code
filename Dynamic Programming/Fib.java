import java.io.*;
import java.util.*;

class Fib {
    public static int Mem(int[] arr, int n) {
        //Memorization
        if (n <= 1)
            return n;
        if (arr[n] != -1)
            return arr[n];
        return arr[n] = Mem(arr, n - 1) + Mem(arr, n - 2);
    }

    public static int Tab(int[] arr, int n) {
        //Tabulation
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i <= n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }

    public static void main(String[] args) {
        int n = 5;
        int[] arr = new int[n + 1];
        Arrays.fill(arr, -1);
        System.out.println(Mem(arr, n));
        System.out.println(Tab(arr, n));
    }
}