#include <iostream>
#include <stdlib.h>
#include <stack>
#include <vector>

using namespace std;

class MinStack {
private:
    struct cell{
        int value;
        cell* next;
        int min_value_when_entered;
    };

    cell* stack = nullptr;
    int min = 2147483647; // integer max value
public:
    void push(int value) {
        cell* aux = new cell;
        aux->value = value;
        aux->next = stack;
        aux->min_value_when_entered = min;

        if(value < min)
            min = value;

        stack = aux;
    }
    
    void pop() {
        cell* to_del = stack;
        if(stack->value == min)
            min = stack->min_value_when_entered;
        stack = stack->next;
        delete to_del;
    }
    
    int top() {
        return stack->value;
    }

    int getMin() {
        return min;
    }
};

int main() {
    {
        MinStack minStack;
        bool passed = true;

        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);

        if (minStack.getMin() != -3) passed = false;

        minStack.pop();

        if (minStack.top() != 0) passed = false;

        if (minStack.getMin() != -2) passed = false;

        cout << "Test Case 1: "
             << (passed ? "Accepted" : "Wrong Answer")
             << endl;
    }

    return 0;
}