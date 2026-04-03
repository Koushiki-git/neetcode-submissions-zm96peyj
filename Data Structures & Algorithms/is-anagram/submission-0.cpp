class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        unordered_map<char,int> mppp;
        for(char c:s){
            mpp[c]++;
        }
        for(char c:t){
            mppp[c]++;

        }
        if(mpp==mppp) return true;
        return false;
        
    }
};
