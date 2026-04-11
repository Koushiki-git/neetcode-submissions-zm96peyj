class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x!=0){
            int digit=x%10;//extract the last digit;
            x=x/10;//remove the last digit

            //check overflow before multiplying by 10
            if(res>INT_MAX/10 || res<INT_MIN/10) return 0;
            res=res*10+digit;
            

        }
        return res;
        
    }
};
