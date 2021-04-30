/*Given two sequences pushed and popped with distinct values, return true if and only if this could have been 
the result of a sequence of push and pop operations on an initially empty stack.

Example 1:
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

Example 2:
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.*/

//For each value, push it to the stack.
//Then, greedily pop values from the stack if they are the next values to pop.
//At the end, we check if we have popped all the values successfully.

bool ValidateStackSequence(vector<int> &pushed, vector<int> &popped)
{
	int j = 0 , i;
	stack<int> st;
	int n = pushed.size();
	
	for(i = 0; i < n; i++)
	{
		st.push(pushed[i]);
		while(!st.empty() && j < n && st.top() == popped[j])
		{
			st.pop();
			j++;
		}	
		
	}
	return j == n;
	//return st.size() == 0;
}

// Author: Huahua, 8 ms
class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s;
    auto it = begin(popped);
    for (int e : pushed) {
      s.push(e);
      while (!s.empty() && s.top() == *it) {
        s.pop();
        ++it;
      }
    }
    return it == end(popped);
  }
};