class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            
            //prefix sum +nt in map
            if(mpp.find(k-nums[i])!=mpp.end()){
                v.push_back(mpp[k-nums[i]]);
                v.push_back(i);

            }
            mpp[nums[i]]=i;
        }
        return v;

        
    }
};
