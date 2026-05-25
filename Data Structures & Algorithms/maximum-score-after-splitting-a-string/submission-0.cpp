class Solution {
public:
    int maxScore(string s) {
        
        int score=INT_MIN;
        for(int i=1;i<s.size();i++){
            string left=s.substr(0,i);
            string right=s.substr(i);
            int count_left=0,count_right=0;
            for(char it:left){
                if(it=='0') count_left++;
                else continue;
            }
            for(char it:right){
                if(it=='1') count_right++;
                else continue;
            }
            score=max(score,count_left+count_right);
        }
        return score;
        
        
    }
};