import java.io.*;
import java.util.*;

class HouseRobber {
    public static int FindMax(ArrayList<Integer> arr) {
        int n = arr.size();
        int prev2 = 0, prev = arr.get(0);
        if (n == 0)
            return arr.get(n);
        for (int i = 1; i < n; i++) {
            int notPick = 0 + prev;
            int pick = arr.get(i);
            if (i > 1) {
                pick += prev2;
            }
            int curr = Math.max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    public static int MaxLoot(ArrayList<Integer> arr, int n) {
        // excluding 1st index
        ArrayList<Integer> arr1 = new ArrayList<Integer>();
        // excluding last index
        ArrayList<Integer> arr2 = new ArrayList<Integer>();
        for (int i = 0; i <= n; i++) {
            if (i != 0)
                arr1.add(arr.get(i));
            if (i != n)
                arr2.add(arr.get(i));
        }
        return Math.max(FindMax(arr1), FindMax(arr2));
    }

    public static void main(String[] arg) {
        ArrayList<Integer> arr = new ArrayList<Integer>(Arrays.asList(2, 1, 4, 9));
        System.out.println(MaxLoot(arr, arr.size() - 1));
    }
}
