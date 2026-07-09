#include <iostream>
#include<stdlib.h>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char& c: s) {
            switch(c) {
                case ')':
                    if(st.empty())
                        return false;
                    if(st.top() != '(')
                        return false;
                    st.pop();
                    break;
                case ']':
                    if(st.empty())
                        return false;
                    if(st.top() != '[')
                        return false;
                    st.pop();
                    break;
                case '}':
                    if(st.empty())
                        return false;
                    if(st.top() != '{')
                        return false;
                    st.pop();
                    break;
                default:
                    st.push(c);
                    break;
            }
        }

        return st.empty();
    }
};

int main() {
    Solution solution;

    {
        string input = "()";

        bool expected = true;

        auto result = solution.isValid(input);

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        string input = "()[]{}";

        bool expected = true;

        auto result = solution.isValid(input);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        string input = "(]";

        bool expected = false;

        auto result = solution.isValid(input);

        cout << "Test Case 3: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        string input = "([])";

        bool expected = true;

        auto result = solution.isValid(input);

        cout << "Test Case 4: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        string input = "([)]";

        bool expected = false;

        auto result = solution.isValid(input);

        cout << "Test Case 5: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }
    

    return 0;
}