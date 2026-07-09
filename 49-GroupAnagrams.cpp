#include <iostream>
#include<stdlib.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// class Solution {
// public:
// 
//     string vec_to_string(vector<unsigned int> v) {
//         string ret;
//         for(int i : v) 
//             ret.append(to_string(i) + " ");
//         return ret;
//     }
// 
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> sol;
//         unordered_map<string, vector<string>> m;
// 
//         vector<unsigned int> blueprint = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//         for(string& s: strs) {
//             vector<unsigned int> lm = blueprint;
//             for(char& c: s) 
//                 lm[c-97]++; // note: ASCII a = 97
//             m[vec_to_string(lm)].push_back(s);
//         }
//         
//         for(auto& s: m)
//             sol.push_back(s.second);
// 
//         return sol;
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> sol;
        vector<string> strs_ordered= strs;

        for(string& s : strs_ordered) {
            sort(s.begin(), s.end());
        }

        unordered_set<string> set;
        for(int i=0; i<(int)strs_ordered.size(); i++) {
            if(!set.insert(strs_ordered[i]).second)
                continue;
            vector<string> sol_i;
            sol_i.push_back(strs[i]);
            for(int j=i+1; j<(int)strs_ordered.size(); j++) {
                if(strs_ordered[j] == strs_ordered[i])
                    sol_i.push_back(strs[j]);
            }
            sol.push_back(sol_i);
        }

        return sol;
    }
};

int main() {
    Solution solution;

    {
        vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

        vector<vector<string>> expected = {
            {"bat"},
            {"nat", "tan"},
            {"ate", "eat", "tea"}
        };

        auto result = solution.groupAnagrams(input);

        for (auto& group : result)
            sort(group.begin(), group.end());

        for (auto& group : expected)
            sort(group.begin(), group.end());

        sort(result.begin(), result.end());
        sort(expected.begin(), expected.end());

        cout << "Test Case 1: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<string> input = {""};

        vector<vector<string>> expected = {
            {""}
        };

        auto result = solution.groupAnagrams(input);

        for (auto& group : result)
            sort(group.begin(), group.end());

        for (auto& group : expected)
            sort(group.begin(), group.end());

        sort(result.begin(), result.end());
        sort(expected.begin(), expected.end());

        cout << "Test Case 2: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        vector<string> input = {"a"};

        vector<vector<string>> expected = {
            {"a"}
        };

        auto result = solution.groupAnagrams(input);

        for (auto& group : result)
            sort(group.begin(), group.end());

        for (auto& group : expected)
            sort(group.begin(), group.end());

        sort(result.begin(), result.end());
        sort(expected.begin(), expected.end());

        cout << "Test Case 3: "
             << (result == expected ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}