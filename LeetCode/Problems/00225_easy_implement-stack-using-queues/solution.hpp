#ifndef __WORKBENCH_H__
#define __WORKBENCH_H__

#include <cmath>

#include <algorithm>
#include <queue>

#include "workbench/leetcode.hpp"

using namespace std;

namespace wb {

class MyStack {
  private:
    queue<int> internal_storage;

  public:
    MyStack() {}

    void push(int x) { this->internal_storage.push(x); }

    int pop() {
        int size = this->internal_storage.size();

        for (int i = 0; i < size - 1; i++) {
            this->internal_storage.push(this->internal_storage.front());
            this->internal_storage.pop();
        }

        int back = this->internal_storage.front();
        this->internal_storage.pop();

        return back;
    }

    int top() { return this->internal_storage.back(); }

    bool empty() { return this->internal_storage.empty(); }
};

} // namespace wb

#endif
