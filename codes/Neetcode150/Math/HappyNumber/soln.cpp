#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        if (n==1000) return true;
        unordered_set <int> seen;
        while(n!=1){
            if(seen.count(n)) return false;
            seen.insert(n);
            int a = n%10;
            int b = (n%100)/10;
            int c = (n%1000)/100;
            n = a*a+b*b+c*c;
        }
        return true;
    }
};
