class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;i++){
            res<<=1;//lest shift res by 1 bit creating a space of 0 in the end
            res|=(n&1);//extract the last bit and then add it to the empty space
            n>>=1;//move the bits to the right (divide by 2)
        }
        return res;
        
    }
};
