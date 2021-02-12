#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <stack>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class MyQueue {
  private:
    stack<int> internal_stack;

  public:
    MyQueue() {}

    void push(int x) {
        stack<int> tmp_stack;

        while (!this->internal_stack.empty()) {
            tmp_stack.push(this->internal_stack.top());
            this->internal_stack.pop();
        }

        this->internal_stack.push(x);
        while (!tmp_stack.empty()) {
            this->internal_stack.push(tmp_stack.top());
            tmp_stack.pop();
        }
    }

    int pop() {
        int front = this->internal_stack.top();
        this->internal_stack.pop();
        return front;
    }

    int peek() { return this->internal_stack.top(); }

    bool empty() { return this->internal_stack.empty(); }
};

} // namespace wb

#endif
