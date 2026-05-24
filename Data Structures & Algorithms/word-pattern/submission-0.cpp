class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);//splits the sentences into words
        //extracting the word and storing it in wirds vector
        vector<string> words;//to store the words in s
        string word;
        unordered_map<char,string> mp1;
        unordered_map<string,char>mp2;
        while(ss>>word){
            words.push_back(word);
        }
        if(words.size()!=pattern.size()) return false;
        for(int i=0;i<pattern.size();i++){
            char ch=pattern[i];
            string w=words[i];
            
            if(mp1.count(ch) && mp1[ch]!=w) return false;
            if(mp2.count(w) && mp2[w]!=ch) return false;
            mp1[ch]=w;
            mp2[w]=ch;


        }
        return true;
        
    }
};