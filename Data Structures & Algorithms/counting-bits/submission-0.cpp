class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int i=1;i<=n;i++){
            // remove the last bit and get the last bit 
            //res[i]=res[i/2]+(i%2)
            res[i]=res[i>>1]+(i&1);
        }
        return res;
        
    }
};
