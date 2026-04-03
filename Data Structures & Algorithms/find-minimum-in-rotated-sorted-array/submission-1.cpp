class Solution {
public:
    int findMin(vector<int> &nums) {
        //if el> left el and right el then right el is the smallest
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            //check if left half sorted
            if(nums[mid]>nums[high]){
                //min in right half
                low=mid+1;
            }
            else{
                //minimum in left half including mid
                high=mid;
            }
            
        }
        return nums[low];//l==r
        
    }
};
