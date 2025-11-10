#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if (nums.size() <= 2) return -1;
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]].emplace_back(i);
        }
        int minDist = INT_MAX;
        int gd;
        bool found=false;
        for (auto& [num, indices] : um) {
            if(indices.size() > 2){
                found=true;
                for(int i = 0; i <= indices.size()-3; i++){
                    gd = abs(indices[i]-indices[i+1])
                        + abs(indices[i+1]-indices[i+2])
                        + abs(indices[i+2]-indices[i]);
                    minDist = min(minDist, gd);
                }
            }
        }
        return found ? minDist : -1;
    }
};