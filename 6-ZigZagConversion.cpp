#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if ((int)s.length() <= numRows || numRows == 1)
            return s;
        string sol = "";
        for (int row = 0; row < numRows; row++) {
            int col = 0;
            int index = row + col * (2 * numRows - 2);
            while (index < (int)s.length() + (index-numRows) % (2*numRows-2)) {
                if(index-(2*row) >= 0 && index-(2*row) < (int)s.length() && row != 0 && row != numRows-1)
                    sol.push_back(s.at(index-(2*row)));
                if(index < (int)s.length())
                    sol.push_back(s.at(index));
                col++;
                index = row + col * (2 * numRows - 2);
            }
        }

        return sol;
    }
};

int main() {
    Solution solution;

    {
        string s = "PAYPALISHIRING";
        int numRows = 3;

        string expected = "PAHNAPLSIIGYIR";

        auto result = solution.convert(s, numRows);

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        string s = "PAYPALISHIRING";
        int numRows = 4;

        string expected = "PINALSIGYAHRPI";

        auto result = solution.convert(s, numRows);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        string s = "A";
        int numRows = 1;

        string expected = "A";

        auto result = solution.convert(s, numRows);

        cout << "Test Case 3: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}