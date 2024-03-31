//84. Largest Rectangle in Histogram
//Solved
//Hard
//Topics
//Companies
//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
//
// 
//
//Example 1:
//
//
//Input: heights = [2,1,5,6,2,3]
//Output: 10
//Explanation: The above is a histogram where width of each bar is 1.
//The largest rectangle is shown in the red area, which has an area = 10 units.
//Example 2:
//
//
//Input: heights = [2,4]
//Output: 4
// 
//
//Constraints:
//
//1 <= heights.length <= 105
//0 <= heights[i] <= 104
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
                int n = arr.size();
        //         if( n==1 ) return heights[0];
        //         int left=0,right =1;
        //         int maxArea=INT_MIN;
        //         int currArea;
        //         while(right<n){
        //             if(heights[left] == 0 || heights[right] == 0){
        //                 currArea = max(heights[left],heights[right]);
        //             }else{
        //    currArea = 2 * min(heights[left],heights[right]);
        //             }

        //             left++;
        //             right++;
        //             maxArea = max(maxArea,currArea);
        //         }
        //         return maxArea;
        // haven't passed all
        //  int maxArea = INT_MIN;
        //  for(int i=0;i<arr.size();i++){
        //     int left = i,right = i,currArea=0;
        //     while(left>=0 && arr[i]<=arr[left]){
        //             left--;

        //     }
        //     while(right<arr.size() && arr[i]<=arr[right]){
        //             right++;
        //     }
        //     currArea = (right-left +1) * arr[i];
        //     maxArea = max(maxArea,currArea);

        //  }
        //  return maxArea;

        //
        stack<int> st;
        int leftSmall[n],rightSmall[n];
        for(int i =0;i<n;i++){
            while(!st.empty() && arr[st.top()] >=arr[i]) st.pop();
            if(st.empty()) leftSmall[i] = 0;
            else leftSmall[i] =st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i =n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >=arr[i]) st.pop();
            if(st.empty()) rightSmall[i] = n-1;
            else rightSmall[i] =st.top()-1;
            st.push(i);
        }
        int maxArea = 0;
        for(int i =0;i<n;i++){
            maxArea = max(maxArea,(rightSmall[i]-leftSmall[i]+1)*arr[i]);
        }
        return maxArea;
    }
};
