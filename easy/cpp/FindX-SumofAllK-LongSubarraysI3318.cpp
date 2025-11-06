#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res(nums.size()-k+1, 0);
        unordered_map<int,int> um;
        int i;
        for (i = 0; i < k; i++) {
            um[nums[i]]++;
        }

        vector<pair<int, int>> freq;
        for (const auto& [key, value] : um) {
            freq.emplace_back(value, key);
        }

        sort(freq.begin(), freq.end(), greater<pair<int, int>>());

        for (i = 0; i < x && i<freq.size(); i++) {
            res[0] += freq[i].first * freq[i].second;
        }

        for(i=1; i < nums.size()-k+1; i++){
            bool foundNew = false;
            for (auto &p : freq) {
                if (p.second == nums[i+k-1]) {
                    p.first++;
                    foundNew = true;
                    break;
                }
            }
            
            for (auto it = freq.begin(); it != freq.end(); ++it) {
                if (it->second == nums[i - 1]) {
                    it->first--;
                    if (it->first == 0) {
                        freq.erase(it);
                    }
                    break;
                }
            }

            if (!foundNew) {
                freq.emplace_back(1, nums[i+k-1]);
            }
            sort(freq.begin(), freq.end(), greater<pair<int, int>>());
            for (int h = 0; h < x && h < freq.size(); h++) {
                res[i] += freq[h].first * freq[h].second;
            }
        }

        return res;

    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,1,1,4};
    vector<int> res = sol.findXSum(nums, 2, 2);
    return 0;
}
