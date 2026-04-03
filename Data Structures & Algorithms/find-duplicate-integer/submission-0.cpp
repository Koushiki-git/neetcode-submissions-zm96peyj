class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num:nums){
            //if num is +nt already in set
            if(seen.find(num)!=seen.end()){
                return num;
            }
            seen.insert(num);//if seen for the first time add to set
        }
        
    }
};
