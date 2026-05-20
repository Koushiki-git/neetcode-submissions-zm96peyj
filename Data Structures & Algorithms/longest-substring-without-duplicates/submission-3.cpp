class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        vector<int> lastidx(256,-1);
        int maxl=0;
        for(int r=0;r<s.length();r++){
            //if already seen in current window
            if(lastidx[s[r]]>=left){
                left=lastidx[s[r]]+1;
            }
            lastidx[s[r]]=r;
            maxl=max(maxl,r-left+1);
        }
        return maxl;
        
    }
};
