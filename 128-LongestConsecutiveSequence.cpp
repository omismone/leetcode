#include <iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        unordered_set<int> s;
        for(int& n : nums)
            s.insert(n);
        int max_length = 1;
        for(int n : s) {
            if(s.find(n-1) == s.end()) { // n - 1 not present in s
                int cur = n;
                while(s.find(cur) != s.end())
                    cur++;
                max_length = max(max_length, cur - n);
            }
        }
        return max_length;
    }
};

int main() {
    Solution solution;

    {
        vector<int> input = {100, 4, 200, 1, 3, 2};

        int expected = 4;

        auto result = solution.longestConsecutive(input);

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> input = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

        int expected = 9;

        auto result = solution.longestConsecutive(input);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> input = {1, 0, 1, 2};

        int expected = 3;

        auto result = solution.longestConsecutive(input);

        cout << "Test Case 3: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}