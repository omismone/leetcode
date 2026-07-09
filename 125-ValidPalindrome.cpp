#include <iostream>
#include<stdlib.h>
#include <string>

using namespace std;

class Solution {
public:
    void clean_string(string& s) {
        int length = s.length();
        for(int i=0; i<length; i++) {
            char c = s[i];
            // ascii numbers are from 48 to 57 decimal
            // upper case letters are from 65 to 90
            // lower case letters are from 97 to 122
            if(c > 64 && c < 91) 
                s[i] = c + 32;
            else if(c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122) {
                s.erase(i, 1);
                i--;
                length--;
            }
        }
    }

    bool isPalindrome(string s) {
        clean_string(s);
        int length = (int)s.length();
        for(int i=0; i<length/2; i++)
            if(s[i] != s[length - 1 - i])
                return false;
        return true;
    }
};

int main() {
    
    Solution solution;

    {
        string input = "A man, a plan, a canal: Panama";
        bool expected = true;
        auto result = solution.isPalindrome(input);

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        string input = "race a car";
        bool expected = false;
        auto result = solution.isPalindrome(input);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        string input = " ";
        bool expected = true;
        auto result = solution.isPalindrome(input);

        cout << "Test Case 3: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }
    
    return 0;
}