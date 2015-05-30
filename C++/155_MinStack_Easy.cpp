/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

Tags: Stack, Data Structure
*/
class MinStack {
private:
    stack<int> s;
    stack<int> smin;
public:
    void push(int x) {
        s.push(x);
        if (smin.empty() || x <= smin.top())
            smin.push(x);
    }

    void pop() {
        int tmp = s.top();
        s.pop();
        if (tmp == smin.top())
            smin.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return smin.top();
    }
};
