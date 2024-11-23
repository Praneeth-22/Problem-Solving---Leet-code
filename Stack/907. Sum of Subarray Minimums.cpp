// 907. Sum of Subarray Minimums
// Attempted
// Medium
// Topics
// Companies
// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444
 

// Constraints:

// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104

class Solution {
public:
    int findMin(vector<int>& v) {
        return *std::min_element(v.begin(), v.end());
    }
    void findNSE(vector<int> arr, vector<int>* nse, int n) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            (*nse)[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    void findPSE(vector<int> arr, vector<int>* pse, int n) {
       stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            (*pse)[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        // burte force
        int sum = 0, n = arr.size(), mod = (int)(1e9 + 7);
        // for (int i = 0; i < n; i++) {
        //     vector<int> temp;
        //     for (int j = i; j < n; j++) {
        //         temp.push_back(arr[j]);
        //         sum += findMin(temp);
        //     }
        // }
        vector<int> nse(n);
        vector<int> pse(n);
        findNSE(arr, &nse, n);
        findPSE(arr, &pse, n);
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            sum = (sum + (1LL * right * left * arr[i]) % mod) % mod;
        }
        return sum ;
    }
};