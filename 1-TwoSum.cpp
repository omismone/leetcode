#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> sol;
        for(int i=0; i<(int)nums.size()-1; i++) {
            for(int j=i+1; j<(int)nums.size(); j++) {
                if(nums.at(i)+nums.at(j) == target) {
                    sol.push_back(i);
                    sol.push_back(j);
                    return sol;
                }
            }
        }
        return sol;
    }
};

int main() {
    Solution solution;

    {
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;

        vector<int> expected = {0, 1};

        auto result = solution.twoSum(nums, target);

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> nums = {3, 2, 4};
        int target = 6;

        vector<int> expected = {1, 2};

        auto result = solution.twoSum(nums, target);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> nums = {3, 3};
        int target = 6;

        vector<int> expected = {0, 1};

        auto result = solution.twoSum(nums, target);

        cout << "Test Case 3: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}