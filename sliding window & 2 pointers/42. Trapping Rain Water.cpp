//42. Trapping Rain Water
//Solved
//Hard
//Topics
//Companies
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
//
// 
//
//Example 1:
//
//
//Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6
//Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
//Example 2:
//
//Input: height = [4,2,0,3,2,5]
//Output: 9
// 
//
//Constraints:
//
//n == height.length
//1 <= n <= 2 * 104
//0 <= height[i] <= 105

class Solution {
public:
    int trap(vector<int>& height) {
        int i =0;
        int j =height.size()-1;
        int leftMax = height[i];
        int rightMax = height[j];
        int water=0;
        // while(j<height.size()){
        //      rightMax = height[j];
        //     if(rightMax < leftMax){
        //         j++;
        //     }else if (rightMax > leftMax{
        //         water+=(min(rightMax,leftMax)*(j+i-1);
        //         leftMax =rightMax;
        //         i=j;
        //         j++;
        //     }else{
        //         j++;
        //     }
        // }
        while(i<j){
            if(leftMax < rightMax){
                i++;
                leftMax = max(leftMax,height[i]);
                water+=leftMax - height[i];
            }
            else{
                j--;
                rightMax = max(rightMax,height[j]);
                water+=rightMax - height[j];
            }
        }
        return water;
    }
};
