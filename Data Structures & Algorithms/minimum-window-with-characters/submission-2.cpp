class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        int minlen=1e9;
        for(int i=0;i<t.length();i++){
            mpp[t[i]]++;
        }
        int cnt=mpp.size();//number of unique characters
        int i=0,j=0;
        int start=-1;
        
        while(j<s.length()){
            if(mpp.find(s[j])!=mpp.end()){
                mpp[s[j]]--;
                if(mpp[s[j]]==0) cnt--;
            }
            
            while(cnt==0)//we got our window
            {
                if(j-i+1<minlen){
                    minlen=j-i+1;
                    start=i;
                }
                if(mpp.find(s[i])!=mpp.end()){
                    mpp[s[i]]++;
                    if(mpp[s[i]]>0) cnt++;//invalid window
                    
                }
                i++;
                
                
            }
            j++;
            

        }
        return (start==-1)?"":s.substr(start,minlen);
        
    }
};
