class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        vector<int> freq(26,0);
        int maxl=INT_MIN;
        for(int right=0;right<s.length();right++){
            freq[s[right]-'A']++;//count the freq of each char
            int maxfreq=max(maxfreq,freq[s[right]-'A']);//we got the max freq char so the different char will we converted to this 
            
            while((right-left+1)-maxfreq>k){//no of diff char >k
                //shrink from left
                freq[s[left]-'A']--;
                left++;

            }
            maxl=max(maxl,right-left+1);



        }
        return maxl;

       

        
        
    }
};
