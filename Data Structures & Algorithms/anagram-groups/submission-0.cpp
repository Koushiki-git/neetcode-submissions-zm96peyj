class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        //key-->freq pattern of characters
        //value--> list of anagrams
        for (string &s:strs){
            
            vector<int> freq(26,0);
            //transform the freq array
            for( char c:s){
                freq[c-'a']++;
            }
            string key=" "; //create unique key from freq array

            //convert the freq array into string
            for(int i=0;i<26;i++){
                key+="#"+to_string(freq[i]);
            }
            mp[key].push_back(s);//all same freq elements in 1 group
        }
        vector<vector<string>> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        

        
    }
};
