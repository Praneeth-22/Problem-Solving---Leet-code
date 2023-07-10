import java.util.*;
import java.io.*;
public class ImplementLowerBound {
    public  int findFirstOccurance(ArrayList<Integer> arr,int el){
        int low =0,high = arr.size()-1;
        int loc =high;
       
        while(low<=high){
             int mid = (low+high)/2;
            if(el >= arr.get(mid)){
                loc = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return loc;
    }
    public static void main(String [] args){
        ImplementLowerBound i = new ImplementLowerBound();
        ArrayList<Integer> arr = new ArrayList<Integer>(Arrays.asList(1,2,2,3,4));
       System.out.print("->"+i.findFirstOccurance(arr,2));
    }
}
