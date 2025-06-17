class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = profit.size();
        vector<int> ans = {0,0}; // number of jobs , profit
        vector<pair<int,int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({deadline[i],profit[i]});
        }
        //sort in ascending order
        sort(jobs.begin(),jobs.end());
        // creating a min_heap 
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto job: jobs){
            //if job can be scheduled within its deadline, compared jobs with same dealines
            if(job.first >pq.size()) pq.push(job.second);
            //replace the job with the lowest profit in heap with new incomming profit of same deadline
            else if (!pq.empty() && pq.top() < job.second){
                pq.pop();
                pq.push(job.second);
            }
        }
        while(!pq.empty()){
            ans[1]+=pq.top();
            pq.pop();
            ans[0]++;
        }
        return ans;
    }
    
};
int main() {
    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit = {100, 19, 27, 25, 15};
    Solution sol;
    vector<int> ans = sol.jobSequencing(deadline, profit);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}