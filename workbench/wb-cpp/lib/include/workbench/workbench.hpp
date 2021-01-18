#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <algorithm>
#include <climits>
#include <stack>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class MinStack {
  private:
    stack<int> storage;
    int minimum;

  public:
    MinStack() { this->minimum = INT_MAX; }

    void push(int x) {
        if (x <= this->minimum) {
            this->storage.push(this->minimum);
            this->minimum = x;
        }
        this->storage.push(x);
    }

    void pop() {
        if (this->storage.top() == this->minimum) {
            this->storage.pop();
            this->minimum = this->storage.top();
            this->storage.pop();
        } else {
            this->storage.pop();
        }
    }

    int top() { return this->storage.top(); }
    int getMin() { return this->minimum; }
};

} // namespace wb

#endif
