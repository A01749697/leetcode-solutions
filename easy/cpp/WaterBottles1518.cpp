#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int residuo;
        int cociente;
        while (numBottles >= numExchange) {
            residuo = numBottles % numExchange;
            cociente = numBottles / numExchange;
            res += cociente;
            numBottles = cociente + residuo;
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.numWaterBottles(9, 3) << endl;
    return 0;
}
