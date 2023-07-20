import java.io.*;
import java.util.*;

class searchElement {
    public static int find(int[] arr, int el) {
        // int pos = -1;
        // int curr =0;
        // int flag =0;
        // for(int i=1;i<arr.length;i++){
        // if (arr[i]- arr[curr] ==1){
        // curr++;
        // }
        // else {
        // flag = 1;
        // pos = arr[i];
        // break;
        // }
        // }
        // return pos;

        int low = 0;
        int high = arr.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == el)
                return mid;
            else if (arr[low] <= arr[mid]) {
                if (arr[low] <= el && el <= arr[mid]) {
                    high = --mid;
                } else {
                    low = ++mid;
                }
            } else {
                if (arr[mid] <= el && el <= arr[high]) {
                    low = ++mid;
                } else {
                    high = --mid;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = { 4, 5, 6, 7, 0, 1, 2, 3 };
        int el = 0;
        System.out.println(find(arr, el));
    }
}