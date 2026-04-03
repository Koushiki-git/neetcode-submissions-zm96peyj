class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        while(true){
            slow=nums[slow];//move 1 step
            fast=nums[nums[fast]];
            if(slow==fast) break;
        }
        //find start of cycle
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];

        }
        return slow;
        
    }
};
