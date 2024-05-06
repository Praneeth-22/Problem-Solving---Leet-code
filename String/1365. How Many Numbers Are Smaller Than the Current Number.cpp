class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> ans;
        // for(int i=0; i<n; i++){
        //     int temp = nums[i], count = 0;
        //     for(int j=0; j<n; j++){
        //         if(nums[j] < temp){
        //             count++;
        //         }
        //     }
        //     ans.push_back(count);
        // }

        // return ans;
        vector<int> freq(101, 0); 

        for (int num : nums) {
            freq[num]++;
        }

        for (int i = 1; i < freq.size(); i++) {
            freq[i] += freq[i - 1];
        }

        vector<int> ans;
        for (int num : nums) {
            ans.push_back(num == 0 ? 0 : freq[num - 1]); 
        }
        
        return ans;
    }
};
