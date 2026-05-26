class Solution {
public:
    int longestPalindrome(string s) {
        // 1 odd freq el and rest all even freq elements
        // odd freq el in the middle
        unordered_map<char,int> freq;
        int len=0;
        bool oddfound=false;
        for(char ch:s){
            freq[ch]++;
        }
        
        for(auto it:freq){
            // we take all even freq els
            if(it.second % 2 ==0){
                len+=it.second;
            }
            else{
                len+=it.second-1;//take only the even part 
                oddfound=true;
            }
            
            

        }
        if(oddfound){
            len++;
        }
            
        
        return len;
        
    }
};