/*Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations 
are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. 
It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, 
once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. 
But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.*/

class MyCircularQueue {
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	int n;
	vector<int> qu;
	MyCircularQueue(int k) {
		n=k;

	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if(qu.size()==n) return false;
		qu.push_back(value);
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if(qu.size()==0) return false;
		qu.erase(qu.begin());
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if(qu.size()==0) return -1;
		return qu[0];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if(qu.size()==0) return -1;
		return qu.back();
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		if(qu.size()==0) return true;
		return false;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		if(qu.size()==n) return true;
		return false;
	}
};

//Solution 2
class MyCircularQueue {
    
    int front ;
    int rear;
    vector<int> arr;
    int cs;
    int ms;//max size
    
    
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
       arr= vector<int> (k,0);
       // arr= new int [ms];
        front = 0;
        rear=k-1;
        cs=0;
        ms=k;
        
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
       if(!isFull()) 
       {
           rear=(rear+1)%ms;
           arr[rear]=value;
           cs++;
           return true;
       }
       return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(!isEmpty()){
          front =(front+1)%ms;
            cs--;
            return true;
        }
       return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
            return -1;
       return arr[front] ;
        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
            return -1;
      return arr[rear];  
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (cs == 0);
        
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
      return  (cs==ms);
        
    }
};
