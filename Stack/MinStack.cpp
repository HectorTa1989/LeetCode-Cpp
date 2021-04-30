//Method 1
class MinStack {
     stack<pair<int, int>> st;

public:
    void push(int x) {
        int min;
        if (st.empty()) {
            min = x;
        }
        else {
            min = std::min(st.top().second,x);
        }
        st.push({x, min});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

//Method 2: Dequeue
class MinStack {
	public:

		deque<pair<int,int>> d;    // value and current minimum

/** initialize your data structure here. */
		MinStack() {
	}

	void push(int x) {
		if (d.empty())
		{
			d.push_back(make_pair(x,x));
		}
		else
		{
			int curMin = min(x,d.back().second);
			d.push_back(make_pair(x,curMin));    // A long with value, store current minimum.
		}
	}

	void pop() 
	{
		d.pop_back();        
	}

	int top() {
		return d.back().first;
	}

	int getMin() {
		return d.back().second;
	}
};

//Method 3
class Solution
{
	private:
		stack<int> s1;
		stack<int> nextMin;
		
	public:
		void push(int x)
		{
			if(s1.empty())
				nextMin.push(x);			
			
			else if(nextMin.empty() || x <= getMin()) 
				nextMin.push(x);
			s1.push(x);
		}
		void pop()
		{
			if(s1.top() == getMin()) 
				nextMin.pop();
			s1.pop();
		}
		int top()
		{
			return s1.top();
		}
		int getMin()
		{
			return nextMin.top();
		}
		
};