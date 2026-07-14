#include<iostream>
#include<vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    void reverse(ListNode*& head) {
        if(head == nullptr)
            return;
        if(head->next == nullptr)
            return;
        ListNode* aux = head->next;
        reverse(aux);
        head->next->next = head;
        head->next = nullptr;
        head = aux;
    }

    ListNode* reverseList(ListNode* head) {
        reverse(head);
        return head;
    }
};

int main() 
{
    Solution solution;

    {
        ListNode* input = new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(4,
                        new ListNode(5)))));

        vector<int> expected = {5, 4, 3, 2, 1};

        ListNode* result = solution.reverseList(input);

        bool ok = true;
        for (int x : expected) {
            if (result == nullptr || result->val != x) {
                ok = false;
                break;
            }
            result = result->next;
        }

        cout << "Test Case 1: "
             << (ok && result == nullptr ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        ListNode* input = new ListNode(1,
                        new ListNode(2));

        vector<int> expected = {2, 1};

        ListNode* result = solution.reverseList(input);

        bool ok = true;
        for (int x : expected) {
            if (result == nullptr || result->val != x) {
                ok = false;
                break;
            }
            result = result->next;
        }

        cout << "Test Case 2: "
             << (ok && result == nullptr ? "Accepted" : "Wrong Answer")
             << endl;
    }

    {
        ListNode* input = nullptr;

        vector<int> expected = {};

        ListNode* result = solution.reverseList(input);

        bool ok = true;
        for (int x : expected) {
            if (result == nullptr || result->val != x) {
                ok = false;
                break;
            }
            result = result->next;
        }

        cout << "Test Case 3: "
             << (ok && result == nullptr ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}