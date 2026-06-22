#include <cstdint>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        for(int i=0;i<32;i++){
            ret=ret<<1;
            uint32_t temp=n>>i;
            temp=temp&1;
            ret = ret|temp;
        }
        return ret;
    }
};
