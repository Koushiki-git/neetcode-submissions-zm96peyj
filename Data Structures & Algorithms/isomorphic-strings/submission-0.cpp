class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;
        for(int i=0;i<s.size();i++){
            char a=s[i];
            char b=t[i];
            // if a already in mp1 and not getting mapped to b
            if(mp1.count(a) && mp1[a]!=b){
                return false;
            }
            // if b already in mp2 and not getting mapped to a
            if(mp2.count(b) && mp2[b]!=a){
                return false;
            }
            mp1[a]=b;
            mp2[b]=a;
        }
        return true;
    }
};