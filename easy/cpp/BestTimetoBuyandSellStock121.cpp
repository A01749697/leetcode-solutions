#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1){
            return 0;
        }
        int minIndex;
        int mp;
        int i;
        int newMinIndex = -1;
        if(prices[1] - prices[0] <= 0){
            mp = 0;
            minIndex = 1;
        }else{
            mp = prices[1] - prices[0];
            minIndex = 0;
        }
        
        for(i = 1; i < prices.size()-1; i++){
            if(prices[i+1]-prices[minIndex] > mp){
                mp = prices[i+1]-prices[minIndex];
            }
            if(newMinIndex != -1){
                if(prices[i+1]-prices[newMinIndex] > mp){
                    mp = prices[i+1]-prices[newMinIndex];
                    minIndex = newMinIndex;
                    newMinIndex = -1;
                }
            }
            if(prices[i+1] < prices[minIndex]){
                if(newMinIndex == -1){
                    newMinIndex = i+1;
                }else{
                    if(prices[i+1] < prices[newMinIndex]){
                        newMinIndex = i+1;
                    }
                }
            }
        }
        return mp;
    }
};