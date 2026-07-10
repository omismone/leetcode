
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    int recursiveSearch(vector<int>& nums, int target, int starting_index, int ending_index) {
        if(starting_index > ending_index)
            return -1;
        int mid = (starting_index + ending_index) / 2;
        if(target < nums[mid])
            return recursiveSearch(nums, target, 0, mid-1);
        if(target > nums[mid])
            return recursiveSearch(nums, target, mid+1, ending_index);
        return mid;
    }

    int search(vector<int>& nums, int target) {
        return recursiveSearch(nums, target, 0, (int)nums.size()-1);
    }
};

int main() {
    Solution solution;

    {
        vector<int> nums = {-1, 0, 3, 5, 9, 12};
        int target = 9;

        int expected = 4;

        auto result = solution.search(nums, target);

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> nums = {-1, 0, 3, 5, 9, 12};
        int target = 2;

        int expected = -1;

        auto result = solution.search(nums, target);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}