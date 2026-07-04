class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r=INT_MIN;
        for(auto pile:piles){
            if(pile>r)r=pile;
        }
        int l=1;
        int mid;
        int sum;
        while(l<=r){
            mid=(l+r)/2;
            
            sum=0;
            for(auto pile:piles){
                sum+=(pile+mid-1)/mid;
            }
            if(sum<=h){
                r=mid-1;
            }
            else if(sum>h) l=mid+1;
        }
        if(sum<=h) return mid;
        if(sum>h) return mid+1;

    }
};
