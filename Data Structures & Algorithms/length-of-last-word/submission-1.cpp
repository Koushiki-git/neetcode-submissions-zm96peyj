class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        while(i>=0 && s[i]==' '){
            i--;//skip spaces starting from the end
        }
        int len=0;
        while(i>=0 && s[i]!=' '){
            len++;
            i--;
        }
        return len;

        
    }
};