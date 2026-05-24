class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> freq;
       
        for(char c:s){
            freq[c]++;
            
        }
        int maxodd=0;
        int mineven=INT_MAX;
        for(auto it:freq){
            int count=it.second;
            if(count%2 !=0){
                maxodd=max(maxodd,count);
            }
            else{
                mineven=min(mineven,count);
            }
        }
        return maxodd-mineven;
      
            
        
    }
};