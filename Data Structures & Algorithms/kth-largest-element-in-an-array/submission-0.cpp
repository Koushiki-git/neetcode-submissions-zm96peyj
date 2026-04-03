class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        //min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int num:nums){
            pq.push(num);

            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        int ans=res[0];
        return ans;
        
    }
};
