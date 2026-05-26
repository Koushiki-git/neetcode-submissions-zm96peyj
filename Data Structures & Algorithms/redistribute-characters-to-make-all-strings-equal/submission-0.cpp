class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26,0);

        //count the freq of all char
        for(string word:words){
            for(char ch:word){
                freq[ch-'a']++;
            }

        }
        //check if all freq is divisible by total no of strings in words
        for(int count:freq){
            if(count%words.size() !=0) return false;

        }
        return true;
        
    }
};