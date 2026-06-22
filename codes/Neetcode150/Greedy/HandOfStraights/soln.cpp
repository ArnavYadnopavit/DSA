#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        unordered_map <int,int> cards;
        for(auto card:hand){
            cards[card]++;
        }
        for(auto num:hand){
            int start=num;
            while(cards[start-1]>0) start--;
            while(start<=num){
                while(cards[start]>0){
                    for(int i=start;i<start+groupSize;i++){
                        if(cards[i]==0) return false;
                        cards[i]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};
