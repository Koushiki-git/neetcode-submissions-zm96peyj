class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> freq;
        for(char ch:allowed){
            freq[ch]++;
        }
        int count=0;
        
        for(auto word:words){
            bool flag=true;
            for(char ch:word){
                
                if(freq[ch]==0){
                    flag=false;
                }
               
            }
            if(flag==true) count++;
        }
        return count;
        
    }
};