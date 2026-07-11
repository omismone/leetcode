
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = (int)nums.size();
        vector<int> answer(l);
        vector<int> v1(l+1, 1);
        vector<int> v2(l+1, 1);

        int prod1 = 1;
        int prod2 = 1;
        
        for(int i=0; i<l; i++) {
            prod1 *= nums[i];
            prod2 *= nums[l-1-i];
            v1[i+1] = prod1;
            v2[l-1-i] = prod2;
        }
        
        for(int i=0; i<l; i++)
            answer[i] = v1[i] * v2[i+1];

        return answer;
    }
};

int main() {
    Solution solution;

    {
        vector<int> nums = {1, 2, 3, 4};

        vector<int> expected = {24, 12, 8, 6};

        auto result = solution.productExceptSelf(nums);

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> nums = {-1, 1, 0, -3, 3};

        vector<int> expected = {0, 0, 9, 0, 0};

        auto result = solution.productExceptSelf(nums);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}