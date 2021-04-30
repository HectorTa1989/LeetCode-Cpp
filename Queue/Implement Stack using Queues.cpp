//https://zxi.mytechroad.com/blog/data-structure/leetcode-225-implement-stack-using-queues/
//Time complexity:
//Push: O(n)
//Pop/top/empty: O(1)
//Space complexity: O(n)
class MyStack {
public:
  /** Initialize your data structure here. */
  MyStack() {}
 
  /** Push element x onto stack. */
  void push(int x) {
    q_.push(x);
    for (int i = 1; i < q_.size(); ++i) {
      q_.push(q_.front());
      q_.pop();
    }
  }
 
  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int top = q_.front();
    q_.pop();
    return top;
  }
 
  /** Get the top element. */
  int top() {
    return q_.front();
  }
 
  /** Returns whether the stack is empty. */
  bool empty() {
    return q_.empty();
  }
private:
  queue<int> q_;  
};
//
class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i=1; i<q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

//
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        myStack.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int len = myStack.size();
        for(int i = 0; i < len - 1; i++) {
            myStack.push(myStack.front());
            myStack.pop();
        }
        myStack.pop();
    }

    // Get the top element.
    int top() {
        int len = myStack.size();
        if(len) {
            for(int i = 0; i < len - 1; i++) {
                myStack.push(myStack.front());
                myStack.pop();
            }
        }
        int ans = myStack.front();
        myStack.push(ans);
        myStack.pop();
        return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        return myStack.empty();
    }
private:
    std::queue<int> myStack;
};

//
class Stack {
    public:
    // Push element x onto stack.
    void push(int x) {
        if( q1.empty() ){ 
            q1.push(x);
            while (!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        else{ 
            q2.push(x); 
            while (!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if (!q1.empty()) { q1.pop(); }
        else{ q2.pop(); }
    }

    // Get the top element.
    int top() {
        if (!q1.empty()) { return q1.front(); }
        else{ return q2.front(); }
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1, q2;
};