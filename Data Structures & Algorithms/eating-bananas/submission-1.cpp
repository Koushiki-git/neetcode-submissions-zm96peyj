class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;

        //return the max element in piles array
        int r=*max_element(piles.begin(),piles.end());
        //max eating speed=max el. At this spped KOKO can finish any pile in 1 hour
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long hours=0;
            for(int pile:piles){
                hours+=(pile+mid-1)/mid;

            }
            if(hours<=h){
                ans=mid;
                //we want minimum k
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return ans;
    }
};
