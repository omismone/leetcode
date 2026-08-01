#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 1) return 0;
        int min = prices[0];
        int max_profit = 0;
        for(int i=0; i<(int)prices.size(); i++) {
            if(prices[i] < min)
                min = prices[i];
            else
                max_profit = max_profit < prices[i]-min ? prices[i]-min : max_profit;
        }

        return max_profit;
    }
};

int main() {
    Solution solution;

    {
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        
        int expected = 5;

        auto result = solution.maxProfit(prices);

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> prices = {7, 6, 4, 3, 1};
        
        int expected = 0;

        auto result = solution.maxProfit(prices);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}