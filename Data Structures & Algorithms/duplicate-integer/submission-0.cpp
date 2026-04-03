class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int it:nums){
            mpp[it]++;
            if(mpp[it]>1) return true;
        }
        return false;
        
    }
};