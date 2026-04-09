class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //we treat nums like a ll
        //nums[i] is the next pointer
        //i->nums[i]
        //index=node, value=next pointer
        int slow=nums[0];//moves by 1 step
        int fast=nums[nums[0]];//moves by 2 steps

        //find meeting point inside the cycle
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }

        //find the entrance of cycle
        slow=0;//reset slow
        //move both 1 step at a time 
        //They'll meet at the duplicate number
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;//duplicate number


        
    }
};
