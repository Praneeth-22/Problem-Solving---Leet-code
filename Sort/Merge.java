import java.io.*;

class Merge {
    public static void sort(int[] arr, int low, int high, int mid) {
        int temp[] = new int[high - low + 1];
        int left = low;
        int idx = 0;
        int right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[idx++] = arr[left++];
            } else {
                temp[idx++] = arr[right++];
            }
        }
        while (left <= mid) {
            temp[idx++] = arr[left++];
        }
        while (right <= high) {
            temp[idx++] = arr[right++];
        }
        for (int i = low; i <= high; i++) {
            System.out.println("val-" + arr[i]);
            arr[i] = temp[i - low];
        }
    }

    public static void divide(int[] arr, int low, int high) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        System.out.println("mid-" + mid);
        divide(arr, low, mid);
        divide(arr, mid + 1, high);
        sort(arr, low, high, mid);
    }

    public static void main(String[] args) {
        int[] arr = { 3, 2, 4, 1, 3 };
        int len = arr.length;
        System.out.println("len-" + len);
        divide(arr, 0, len - 1);
        for (int i = 0; i < arr.length; i++)
            System.out.println("-" + arr[i]);
    }
}