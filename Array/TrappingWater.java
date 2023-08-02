import java.util.*;
import java.io.*;

class TrappingWater {
    public static int trapped(int[] arr, int n) {
        int left = 0;
        int right = n - 1;
        int leftMax = 0, rightMax = 0;
        int count = 0;
        while (left <= right) {
            if (arr[left] <= arr[right]) {
                if (arr[left] > leftMax) {
                    leftMax = arr[left];
                } else {
                    count += leftMax - arr[left];
                }
                left++;
            } else {
                if (arr[right] > rightMax) {
                    rightMax = arr[right];
                } else {
                    count += rightMax - arr[right];
                }
                right--;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] arr = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        System.out.println("water trapped:" + trapped(arr, arr.length));
    }
}