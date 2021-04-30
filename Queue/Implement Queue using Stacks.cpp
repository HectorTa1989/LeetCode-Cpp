class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while (!st.empty()) {
            tmp.push(st.top()); st.pop();
        }
        st.push(x);
        while (!tmp.empty()) {
            st.push(tmp.top()); tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = st.top(); st.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return st.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
    
private:
    stack<int> st;
};

//Solution 2
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        _new.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        shiftStack();
        int val = _old.top(); _old.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        shiftStack();
        return _old.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _old.empty() && _new.empty();
    }
    
    void shiftStack() {
        if (!_old.empty()) return;
        while (!_new.empty()) {
            _old.push(_new.top());
            _new.pop();
        }
    }
    
private:
    stack<int> _old, _new;
};

//https://zxi.mytechroad.com/blog/stack/leetcode-232-implement-queue-using-stacks/
//amortized cost: O(1)
class MyQueue {
public:
  /** Initialize your data structure here. */
  MyQueue() {}
 
  /** Push element x to the back of queue. */
  void push(int x) {
    s1_.push(x);
  }
 
  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (s2_.empty()) move();
    int top = s2_.top();
    s2_.pop();
    return top;
  }
 
  /** Get the front element. */
  int peek() {
    if (s2_.empty()) move();
    return s2_.top();
  }
 
  /** Returns whether the queue is empty. */
  bool empty() {
    return s1_.empty() && s2_.empty();
  }
private:
  stack<int> s1_;
  stack<int> s2_;
  
  void move() {
    while (!s1_.empty()) {
      s2_.push(s1_.top());
      s1_.pop();
    }
  }    
};

//
#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <stack>

using std::cout;
using std::cin;
using std::endl;

class myQueue{
private:
  std::stack<int> s1;
  std::stack<int> s2;
public:
  void push(int);
  int pop();
  bool empty();
};

void myQueue::push(int value){
  // Move all elements from s2 onto s1 and then put value on s1
  //
  cout << "pushing " << value << endl;
  while( !s2.empty() ){
    s1.push( s2.top() );
    s2.pop();
  }
  s1.push(value);
}

int myQueue::pop(){
  // Move all elements from s1 onto s2 and pop off elements from s2
  //
  while( !s1.empty() ){
    s2.push( s1.top() );
    s1.pop();
  }
  if( s2.empty() ){
    cout << "ERROR: no elements to pop" << endl;
    assert(0);
  }
  int value = s2.top();
  s2.pop();
  return value;
}

bool myQueue::empty(){
  return s1.empty() && s2.empty();
}

int main(){
  myQueue mq;
  //int value;
  //cout << "Enter a value to push..." << endl;
  //cin >> value;
  mq.push(0);
  mq.push(1);
  mq.push(2);
  while( !mq.empty() ){
    cout << "Popping = " << mq.pop() << endl;
  }
}