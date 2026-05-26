class Solution {
public:
    string customSortString(string order, string s) {
        //permute s st it becomes a subseq of order
        unordered_map<char,int> mp1;
        for(char ch:s){
            mp1[ch]++;
        }
        string ans="";
        for(char ch:order){
            while(mp1[ch]>0){
                ans+=ch;
                mp1[ch]--;
            }
        }
        //if(ans.length()==s.length()) return ans;
        for(auto it:mp1){
            while(it.second > 0){
                ans+=it.first;
                it.second--;
            }
        }
        return ans;

        
    }
};