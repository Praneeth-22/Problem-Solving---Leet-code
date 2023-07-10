import java.util.*;
import java.io.*;

class SearchInsertPosition {
    public static int findPosition(ArrayList<Integer> arr, int el) {
        int low = 0;
        int high = arr.size() - 1;
        int loc = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (el > arr.get(mid)) {
                high = mid-1;
                
            } else {
                loc = mid;
                low = mid+1;
                
            }
        }
        return loc;
    } 

    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>(Arrays.asList(1, 2, 4, 7));
        int el = 6;
        System.out.println("position" + findPosition(arr, el));
    }
}