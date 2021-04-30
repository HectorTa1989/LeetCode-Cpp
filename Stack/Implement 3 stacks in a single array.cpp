#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <set>
#include <map>

using std::cout;
using std::cin;
using std::endl;

class threeArrayStack{
public:
  int stack_size;
private:
  int *stack_array;
  int stack_indices[3];
  int stack_indices_begin[3];
  int stack_indices_end[3];

public:
  threeArrayStack(int);
  ~threeArrayStack();
  void push(int,int);
  int pop(int);
};

threeArrayStack::threeArrayStack(int ss=10) {
  stack_size = ss;
  stack_array = new int[3*ss];
  assert(stack_array);

  stack_indices[0] = 0; // initialize where the pointers for each stack fall
  stack_indices[1] = ss;
  stack_indices[2] = 2*ss;

  stack_indices_begin[0] = 0; // initialize first element in an array
  stack_indices_begin[1] = ss;
  stack_indices_begin[2] = 2*ss; 

  stack_indices_end[0] = ss; // initialize what the "one-past" the end location is (for bounds checking)
  stack_indices_end[1] = 2*ss;
  stack_indices_end[2] = 3*ss;
}

threeArrayStack::~threeArrayStack(){
  if( stack_array ) delete[] stack_array;
}

void threeArrayStack::push(int which_stack, int value){
  assert( which_stack>=0 );
  assert( which_stack<3 );
  // make sure there is space:
  int new_loc = stack_indices[which_stack];
  if( new_loc >= stack_indices_end[which_stack] ){
    cout << "stack is full ... no space to add" << endl;
    assert(false);
  }
  cout << "Pushing: " << value << " onto stack: " << which_stack << endl;
  stack_array[ stack_indices[which_stack] ] = value;
  stack_indices[which_stack] += 1;
}

int threeArrayStack::pop(int which_stack){
  assert( which_stack>=0 );
  assert( which_stack<3 );
  // make sure there is an element to pop:
  int new_loc = stack_indices[which_stack];
  if( new_loc-1 < stack_indices_begin[which_stack] ){
    cout << "stack " << which_stack << " is emtpy ... can not pop" << endl;
    assert(0);
  }
  int value = stack_array[ new_loc-1 ];
  cout << "Poping: " << value << " from stack: " << which_stack << endl;
  stack_indices[which_stack] -= 1;
  return value;
}

int main(){
  int stack_size = 5;
  threeArrayStack TAS(stack_size);
  TAS.push(0, 1);
  TAS.push(0, 2);
  TAS.push(0, 3);
  TAS.push(0, 4);
  TAS.push(0, 5);
  TAS.pop(0);

  TAS.push(1,10);
  TAS.pop(1);
  TAS.push(1,100);
  //TAS.pop(1);
  TAS.pop(1);

  TAS.push(2,-1);
  TAS.pop(2);
  
  return 0;
}

