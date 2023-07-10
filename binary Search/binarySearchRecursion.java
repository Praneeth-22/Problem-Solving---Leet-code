import java.io.*;
import java.lang.*;
import java.util.*;
class BinarySearch {
    public int RecBinary(ArrayList<Integer> v,int el,int start,int end){
      
        
        if(start<=end){
            int mid = (start+end)/2;
            if(v.get(mid) == el){
                return mid;
            }
            if(el < v.get(mid)) return RecBinary(v,el,start,mid--);
            else return RecBinary(v, el, mid++, end);
        }
        return -1;
    }
    public static void main(String [] args){
        BinarySearch b = new BinarySearch();
        ArrayList<Integer> v = new ArrayList<Integer>(Arrays.asList(1,3,4,5,6,10)) ;
        System.out.print(b.RecBinary(v,6,0,v.size()));


    }
}