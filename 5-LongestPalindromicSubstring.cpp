#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string subs = "";
        for(int mid=0; mid<(int)s.length(); mid++) {
            int left = mid;
            int right = mid;
            int aux = mid+1;
            while(aux < (int)s.length()) {
                if(s.at(aux) == s.at(mid))
                    right++;
                else
                    break;
                aux++;
            }
            while(left>=0 && right<(int)s.length() && s.at(left) == s.at(right)) {
                left--;
                right++;
            }
            string n = s.substr(left+1, right-left-1);
            if(n.length() > subs.length())
                subs = n;
        }
        return subs;
    }

    bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s.at(start) != s.at(end))
                return false;
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    Solution solution;

    {
        string s = "babad";
        string expected = "bab"; 

        auto result = solution.longestPalindrome(s);

        cout << "Test Case 1: "
             << (result == expected || result == "aba" ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        string s = "cbbd";
        string expected = "bb";

        auto result = solution.longestPalindrome(s);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}