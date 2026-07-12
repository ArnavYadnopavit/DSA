class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        int out = 0;
        for(int i=0;i<32;i++){
            int abit = a&1;
            int bbit = b&1;
            //cout  << c << abit << bbit <<endl;
            out |= (abit ^ bbit ^ c)<<i;
            c = (abit & bbit) | (abit^bbit)&c;
            a >>=1;
            b>>=1;
        }
        return out;
    }
};
