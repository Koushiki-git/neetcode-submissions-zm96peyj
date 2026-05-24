class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //TC:O(n*m) where n is the no of strings and m is the smallest length string 
        //SC:O(1)
        //take the first string
        // i is the index position of the first string s
        for(int i=0;i<strs[0].size();i++){
            //from the second string onwards check 
            //j is the string no in the array
            for(int j=1;j<strs.size();j++){
                //if out of bounds( index of the first string is more or = the length of the other string) or mismatch with the first string
                if(i>=strs[j].size() || strs[j][i]!=strs[0][i]){
                    return strs[0].substr(0,i);
                }
            

            }
        }
        return strs[0];//complete string matched
        
    }
};