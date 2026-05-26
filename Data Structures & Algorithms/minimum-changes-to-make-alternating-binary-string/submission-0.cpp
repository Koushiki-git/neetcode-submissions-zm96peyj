class Solution {
public:
    int minOperations(string s) {
        int start0=0;//010101
        int start1=0;//101010

        for(int i=0;i<s.length();i++){
            //if even index
            if(i%2==0){
                if(s[i]!='0') start0++;
            }
            else{
                if(s[i]!='1') start0++;
            }
            //if even index
            if(i%2==0){
                if(s[i]!='1') start1++;
            }
            else{
                if(s[i]!='0') start1++;
            }
        }
        return min(start0,start1);




            
        
    }
};