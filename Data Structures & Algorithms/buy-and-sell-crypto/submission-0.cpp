class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // in the current window we are gonna check if the diff is max
        int left=0;
        int maxdiff=0;
        while(left<prices.size()){
            for(int right=left+1;right<prices.size();right++){
                if(prices[right]<prices[left]) continue;//skip
                maxdiff=max(maxdiff,prices[right]-prices[left]);
            }
            left++;

        }
        return maxdiff;
        
    }
};
