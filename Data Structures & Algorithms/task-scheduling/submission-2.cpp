class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);

        //find freq of each char
        for(char t:tasks){
            freq[t-'A']++;
        }

        int maxFreq=*max_element(freq.begin(),freq.end());
        int countMax=0;

        //count no of char having maxFreq
        for(int f:freq){
            if(f==maxFreq){
                countMax++;
            }

        }
        int mini=(maxFreq-1)*(n+1)+countMax;//no of gaps*Each block(1 task and n gaps)+last block doesn't need full spacing
        return max((int)tasks.size(),mini);
    
        
    }
};
