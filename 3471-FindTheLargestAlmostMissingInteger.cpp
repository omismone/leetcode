#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(nums.size() == 0) return -1;

        // find duplicates and put them in a set called "duplicates"
        unordered_set<int> duplicates, tmp;
        int prev_size;
        for(int x : nums) {
            prev_size = tmp.size();
            tmp.emplace(x);
            if(prev_size == (int)tmp.size())
                duplicates.emplace(x);
        }

        // if k=1 the function must return the largest non-duplicate integer
        if(k == 1) {
            int max = -1;
            for(int x : nums)
                max = x > max && duplicates.count(x) == 0 ? x : max;
            return max;
        }

        // if k is equal to the size of nums the function must return the largest integer
        if(k == (int)nums.size())
            return *max_element(nums.begin(), nums.end());
        
        // otherwise the function return the maximum (non-duplicate) between the first and the last value
        int sol = nums[0] > nums[nums.size()-1] ? nums[0] : nums[nums.size()-1];
        if(duplicates.count(nums[0]))
            sol = nums[nums.size()-1];
        if(duplicates.count(nums[nums.size()-1]))
            sol = nums[0];
        if(duplicates.count(nums[0]) && duplicates.count(nums[nums.size()-1]))
            sol = -1;
        return sol;
    }
};

int main() {
    Solution solution;

    {
        vector<int> nums = {3, 9, 2, 1, 7};
        int k = 3;
        int expected = 7;

        auto result = solution.largestInteger(nums, k);

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> nums = {3, 9, 7, 2, 1, 7};
        int k = 4;
        int expected = 3;

        auto result = solution.largestInteger(nums, k);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> nums = {0, 0};
        int k = 1;
        int expected = -1;

        auto result = solution.largestInteger(nums, k);

        cout << "Test Case 3: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}