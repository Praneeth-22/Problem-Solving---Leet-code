import java.util.*;
import java.io.*;

class CountOccurance {
    public static int findLast(int[] arr, int el) {
        int low = 0;
        int high = arr.length - 1;
        int pos = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == el) {
                pos = mid;
                low = mid + 1;
            } else if (arr[mid] < el) {
                low = ++mid;
            } else {
                high = mid - 1;
            }
        }
        return pos;
    }

    public static int findFirst(int[] arr, int el) {
        int low = 0;
        int high = arr.length - 1;
        int pos = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == el) {
                pos = mid;
                high = mid - 1;
            } else if (arr[mid] < el) {
                low = ++mid;
            } else {
                high = mid - 1;
            }
        }
        return pos;
    }

    public static int find(int[] arr, int el) {
        // System.out.println("last" + findLast(arr, el));
        // System.out.println("first" + findFirst(arr, el));
        return findLast(arr, el) - findFirst(arr, el) + 1;
    }

    public static void main(String[] args) {
        int[] arr = { 3, 4, 13, 13, 13, 20, 40 };
        int el = 13;
        System.out.println("count:" + find(arr, el));
    }
}