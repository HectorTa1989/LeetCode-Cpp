#include<iostream>
#include<stack>
#include<string>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s)
        {
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else
            {
                if(st.empty()) return false;
                else if((c == ')' && st.top() != '(') || (c == ']' && st.top() != '[') || (c == '}' && st.top() != '{'))
                { 
                    return false;
                }
                else
                    st.pop();
            }
                        
        }
        return st.empty();
    }
};

// Function to check whether two characters are opening and closing of same type. 

bool ArePair(char opening, char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

bool ValidParentheses(string s)
{
	stack<char> st;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			st.push(s[i]);
			
		else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if(st.empty() || !ArePair(st.top(), s[i]))
				return false;
			else
				st.pop();
		}
	}
	st.empty() ? true:false;
}

int main()
{
	/*Code to test the function AreParanthesesBalanced*/
	string expression;
	cout<<"Enter an expression:  "; // input expression from STDIN/Console
	cin>>expression;
	if(AreParanthesesBalanced(expression))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
}

//Method 2
bool ValidParentheses(string exp)
{
	stack<char> st;
	char x;
	
	for(int i = 0; i < exp.length(); i++)
	{
		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
			st.push(exp[i]);
			
		if(st.empty()) return false;
		
		switch(exp[i])
		{
		case ')':
		{
			x = st.top();
			st.pop();
			if(x == '[' || x == '{')
				return false;
			break;
		}
		case ']':
		
		}
	}
}