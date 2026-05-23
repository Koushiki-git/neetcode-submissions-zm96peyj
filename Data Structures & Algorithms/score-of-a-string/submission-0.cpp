class Solution {
public:
    int scoreOfString(string s) {
        vector<int> scores;
        int val;
        for(char c:s){
            val=c-'a'+97;
            scores.push_back(val);

        }
        int final_score=0;
        for(int i=0;i<scores.size()-1;i++){
            final_score+=abs(scores[i+1]-scores[i]);

        }
        return final_score;
        
    }
};