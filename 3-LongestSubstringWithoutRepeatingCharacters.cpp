#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        lengthOfLongestSubstringAux(s, 0, &max);
        return max;
    }

    void lengthOfLongestSubstringAux(string &s, int start_index, int* current_max) {
        for(int i=start_index; i<(int)s.length(); i++) {
            int first_occ = s.find_first_of(s.at(i), start_index);
            if(first_occ != i) {
                *current_max = i-start_index > *current_max ? i-start_index : *current_max;
                lengthOfLongestSubstringAux(s, first_occ+1, current_max);
                return;
            }
        }
        *current_max = (int)s.length()-start_index > *current_max ? (int)s.length()-start_index : *current_max;
    }
};

int main() {
    Solution solution;

    {
        string s = "abcabcbb";
        
        int expected = 3;

        auto result = solution.lengthOfLongestSubstring(s);

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        string s = "bbbbb";
        
        int expected = 1;

        auto result = solution.lengthOfLongestSubstring(s);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        string s = "pwwkew";
        
        int expected = 3;

        auto result = solution.lengthOfLongestSubstring(s);

        cout << "Test Case 3: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}