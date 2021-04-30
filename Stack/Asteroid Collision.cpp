/*We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet.

Example 1:
Input: 
asteroids = [5, 10, -5]
Output: [5, 10]
Explanation: 
The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
Example 2:
Input: 
asteroids = [8, -8]
Output: []
Explanation: 
The 8 and -8 collide exploding each other.
Example 3:
Input: 
asteroids = [10, 2, -5]
Output: [10]
Explanation: 
The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
	vector<int> res;
	for(int a : asteroids) {
		bool destroyed = false;
		while(res.size() && res.back() > 0 && a < 0 && !destroyed) {
			if(res.back() >= -a) destroyed = true;
			if(res.back() <= -a) res.pop_back();
		}
		if(!destroyed) res.push_back(a);
	}
	return res;
}
};

//
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>s;
        for(auto& x: asteroids)
            if(s.empty() || s.back() < 0 || x > 0) s.push_back(x);
            else{
                while(!s.empty() && s.back() > 0 && abs(x) > s.back()) s.pop_back();
                if(s.empty() || s.back() < 0) s.push_back(x);
                else if(abs(x) == s.back()) s.pop_back();
            }
        return s;
    }
};
//i think creating a separate function to handle collisions makes it more readable, otherwise it is easy to get lost in all the if-else branches
class Solution {
    bool handleCollision(vector<int> &res, int ast){
        // While top of the stack is positive.
        while (!res.empty() && res.back()>0) 
        {
                //  Both asteroids are equal, destroy both.
                if (abs(ast)==abs(res.back())) 
                {   
                    res.pop_back();
                    return true;//asteroid destroyed
                }
                //Stack top is smaller, remove the positive asteroid 
                else if(abs(ast)>abs(res.back()))
                {
                     res.pop_back();
                     continue;
                }
                //  Stack top is larger, negative asteroid is destroyed.
                else if(abs(ast)<abs(res.back()))
                {
                    return true;//asteroid destroyed
                }  
        }
        return false;
    }
    
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res; //simulate stack
        for (int ast: asteroids){
            if (res.empty() || ast>0) res.push_back(ast);
            else if (ast<0) 
            {   // While top of the stack is positive handle collision
                bool asteroidDestroyed = handleCollision(res, ast);
                //if negative asteroid made it all the way to the 
                //bottom of the stack or destroyed all positive asteroids:
                if (!asteroidDestroyed && (res.empty() || res.back() < 0)){
                    res.push_back(ast);
                }
            }
        }
        return res;
        
    }
};

//Stack 1
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        int i=0;
        stack<int> s;
        vector<int> result;
        
        while(i<n){
            if(s.empty()){
                s.push(asteroids[i]);
                i++;
            }
            else{
                if(s.top()>0 && asteroids[i]<0){
                    if(s.top()>abs(asteroids[i]))
                        i++;
                    else if(s.top()<abs(asteroids[i]))
                        s.pop();
                    else{
                        s.pop();
                        i++;
                    }
                }
                else{
                    s.push(asteroids[i]);
                    i++;
                }
            }
        }
        
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};

//Stack 2
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int> s;
    for(auto& x:asteroids){
        if(s.empty())
            s.push(x);
        else{
            if(x<0 and s.top() > 0){
                bool exist = false;
                while (!s.empty() and s.top()>0) {
                    if(s.top() < -x){
                        s.pop();
                        exist = true;
                    }
                    else if(s.top() > -x){
                        exist = false;
                        break;
                    }
                    else{
                        s.pop();
                        exist = false;
                        break;
                    }
                }
                if(exist)
                    s.push(x);
            }
            else
                s.push(x);
        }
    }
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};