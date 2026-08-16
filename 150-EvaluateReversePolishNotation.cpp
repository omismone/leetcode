#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto s : tokens) {
            if(s == "+") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1 + op2);
            }
            else if(s == "-") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1 - op2);
            }
            else if(s == "*") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1 * op2);
            }
            else if(s == "/") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1 / op2);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};

int main() {
    Solution solution;

    {
        vector<string> tokens = {"2", "1", "+", "3", "*"};
        
        int expected = 9;

        auto result = solution.evalRPN(tokens);

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<string> tokens = {"4", "13", "5", "/", "+"};
        
        int expected = 6;

        auto result = solution.evalRPN(tokens);

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        
        int expected = 22;

        auto result = solution.evalRPN(tokens);

        cout << "Test Case 3: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}