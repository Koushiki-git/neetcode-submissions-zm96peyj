class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //deque only stores indices
        // deque stores in decreasing order
        // double ended queue
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {

            //remove elements outside current window
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }  

            //if new el is > others in deque 
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            } 

            dq.push_back(i);//push idx in deque 


            //max in window is always the front of deque
            if(i>=k-1){//valid window of size k
                ans.push_back(nums[dq.front()]);
            } 
        }
        return ans;  
    }
};
