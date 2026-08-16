#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> sol(temperatures.size(), 0);
        stack<int> to_find_for;
        for(int i=0; i<(int)temperatures.size(); ++i) {
            while(!to_find_for.empty() && temperatures[i] > temperatures[to_find_for.top()]) {
                sol[to_find_for.top()] = i - to_find_for.top();
                to_find_for.pop();
            }
            to_find_for.push(i);
        }
        return sol;
    }
};

int main() {
    Solution solution;

    {
        vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
        
        vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};

        auto result = solution.dailyTemperatures(temperatures);

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> temperatures = {30, 40, 50, 60};
        
        vector<int> expected = {1, 1, 1, 0};

        auto result = solution.dailyTemperatures(temperatures);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> temperatures = {30, 60, 90};
        
        vector<int> expected = {1, 1, 0};

        auto result = solution.dailyTemperatures(temperatures);

        cout << "Test Case 3: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> temperatures = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
        
        vector<int> expected = {8, 1, 5, 4, 3, 2, 1, 1, 0, 0};

        auto result = solution.dailyTemperatures(temperatures);

        cout << "Test Case 4: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<int> temperatures = {34, 80, 80, 34, 34, 80, 80, 80, 80, 34};
        
        vector<int> expected = {1, 0, 0, 2, 1, 0, 0, 0, 0, 0};

        auto result = solution.dailyTemperatures(temperatures);

        cout << "Test Case 5: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}