class Solution {
public:
    int getSum(int a, int b) {
        //keep adding until carry becomes 0
        //till carry isn't 0
        while(b!=0){
            int carry=(a&b)<<1;//(a&b) gives the carry position and the carry moves left so << 1
            a=a^b;//sum w/o carry 
            b=carry;//update carry
        }
        return a;
        
    }
};
