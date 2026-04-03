class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();//rows
        int n=matrix[0].size();//cols
        //we treat 2d as a flattened sorted array of size m*n
        
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            //convert 1D to 2D
            //row=how many full rows are covered
            //cols=position inside the curr row
            int row=mid/n;
            int col=mid%n;
            int val=matrix[row][col];
            if(val==target) return true;
            else if(val<target){
                //move to the right
                low=mid+1;
            }
            else high=mid-1;


            
        }
        return false;//target not found
        
    }
};
