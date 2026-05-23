class Solution {
public:
    int scoreOfString(string s) {
        vector<int> ans;
        int val;
        for(char c:s){
            val=c-'a'+97;
            ans.push_back(val);
        }
        int score=0;
        for(int i=0;i<ans.size()-1;i++){
            score+=abs(ans[i+1]-ans[i]);
        }
        return score;
        
    }
};