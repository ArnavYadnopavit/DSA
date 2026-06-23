#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set <int>good;
        for(int i=0;i<triplets.size();i++){
            auto triplet = triplets[i];
            if(triplet[0]>target[0] || triplet[1]>target[1] || triplet[2]>target[2]) {
                continue;
            }
            cout <<i;
            if(triplet[0]==target[0] && triplet[1]==target[1] && triplet[2]==target[2]) return true;
            if(triplet[0]==target[0]) good.insert(0);
            if(triplet[1]==target[1]) good.insert(1);
            if(triplet[2]==target[2]) good.insert(2);
        }
        if(good.count(0) && good.count(1) && good.count(2)) return true;
        return false;



    }
};
