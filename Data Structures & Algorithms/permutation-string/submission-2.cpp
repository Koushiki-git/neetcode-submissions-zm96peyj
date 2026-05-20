class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;//base case

        vector<int> s1count(26,0);
        for(char c:s1){
            s1count[c-'a']++;
        }

        vector<int> windowcount(26,0);
        int left=0;
        for(int right=0;right<s2.length();right++){
            windowcount[s2[right]-'a']++;
            //check if window is valid or not
            while((right-left+1)>s1.length()){
                //shrink
                windowcount[s2[left]-'a']--;
                left++;
            }

            if(windowcount==s1count) return true;
        }
        return false;

        
    }
};
