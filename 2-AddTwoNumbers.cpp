#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_aux = l1;
        ListNode* l2_aux = l2;
        
        ListNode* l3 = new ListNode(l1->val + l2->val);
        addTwoNumbersAux(l1_aux->next, l2_aux->next, l3, l3->val > 9 ? 1 : 0);
        return l3;
    }

    void addTwoNumbersAux(ListNode* l1, ListNode* l2, ListNode* prev, int carry) {
        if(carry != 0)
            prev->val -= 10;
        if(l1 == nullptr && l2 == nullptr) {
            if(carry != 0)
                prev->next = new ListNode(carry);
            return;
        }
        if(l1 == nullptr) {
            prev->next = new ListNode(l2->val + carry);
            addTwoNumbersAux(l1, l2->next, prev->next, prev->next->val > 9 ? 1 : 0);
            return;
        }
        if(l2 == nullptr) {
            prev->next = new ListNode(l1->val + carry);
            addTwoNumbersAux(l1->next, l2, prev->next, prev->next->val > 9 ? 1 : 0);
            return;
        }
        // both l1 and l2 non empty
        prev->next = new ListNode(l1->val + l2->val + carry);
        addTwoNumbersAux(l1->next, l2->next, prev->next, prev->next->val > 9 ? 1 : 0);
    }
};

ListNode* buildList(const vector<int>& v) {
    if (v.empty()) return nullptr;
    ListNode* head = new ListNode(v[0]);
    ListNode* current = head;
    for (size_t i = 1; i < v.size(); ++i) {
        current->next = new ListNode(v[i]);
        current = current->next;
    }
    return head;
}

bool compareLists(ListNode* l1, ListNode* l2) {
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
}

int main() {
    Solution solution;

    {
        ListNode* l1 = buildList({2, 4, 3});
        ListNode* l2 = buildList({5, 6, 4});

        ListNode* expected = buildList({7, 0, 8});

        auto result = solution.addTwoNumbers(l1, l2);

        cout << "Test Case 1: "
             << (compareLists(result, expected) ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        ListNode* l1 = buildList({0});
        ListNode* l2 = buildList({0});

        ListNode* expected = buildList({0});

        auto result = solution.addTwoNumbers(l1, l2);

        cout << "Test Case 2: "
             << (compareLists(result, expected) ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        ListNode* l1 = buildList({9, 9, 9, 9, 9, 9, 9});
        ListNode* l2 = buildList({9, 9, 9, 9});

        ListNode* expected = buildList({8, 9, 9, 9, 0, 0, 0, 1});

        auto result = solution.addTwoNumbers(l1, l2);

        cout << "Test Case 3: "
             << (compareLists(result, expected) ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}