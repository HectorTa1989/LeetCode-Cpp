/*Design your implementation of the circular double-ended queue (deque).

Your implementation should support following operations:

MyCircularDeque(k): Constructor, set the size of the deque to be k.
insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
getRear(): Gets the last item from Deque. If the deque is empty, return -1.
isEmpty(): Checks whether Deque is empty or not. 
isFull(): Checks whether Deque is full or not.*/

class MyCircularDeque {
public:
    vector<int> q;
    int front,rear;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        q.resize(k,0); //resizing the vector(arraysize) with the given size k.
        front=-1; //intially front and rear both points to the -1 location as in case of circular queue happens.
        rear=-1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()){ //checking for queue is full or not.
            return false;
        }
        else{
            if(front==-1){ //in case we are pushing the element in the queue for the first time.
                insertLast(value);
            }
            else{
                front=(front+(q.size()-1))%q.size(); //by this formula front will move to the 1 pos back where it is currently if it is on 0th postion then it will take the last index (Nth) location of the array/vector. just use copy pen and tried this out.
                q[front]=value; //put the value in q of front newly location 
            }
        }
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()){ //checking for queue is full or not.
            return false;
        }
        else{
            if(front==-1){ //in case we are pushing the element in the queue for the first time.
                front=0;
            }
            rear=(rear+1)%q.size(); //move rear by 1 location after where it is currently. If rear is on Nth location of the index in the array then it will move to the 0th location of the array. Remember we have alreay checked for the array full cond. in above if condition.just use copy pen and tried out this formula. 
            q[rear]=value;
        }
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        else{
            if(front==rear){ //if there is only 1 element in the queue.
                front=-1;
                rear=-1;
            }
            else{
                front=(front+1)%q.size();  //moving front by 1
            }
        }
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        else{
            if(front==rear){
                front=-1;
                rear=-1;
            }
            else{
                rear=(rear+(q.size()-1))%q.size();
            }
        }
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return q[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return q[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(front==-1 && rear==-1){
            return true;
        }
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if((rear+1)%q.size()==front){
            return true;
        }
        return false;
    }
};

//Solution 2
class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    vector<int> v;
    int capacity, size, head, tail;
	
    MyCircularDeque(int k) {
        capacity=k;
        size=0;
        head=1;
        tail=-1;
        v=vector<int>(capacity);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(size==capacity)
            return false;
        head=(head-1)%capacity;
        if(head<0)
            head+=capacity;
        v[head]=value;
        size++;
        if(size==1)
            tail=head;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(size==capacity)
            return false;
        tail=(tail+1)%capacity;
        v[tail]=value;
        size++;
        if(size==1)
            head=tail;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(size==0)
            return false;
        head=(head+1)%capacity;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(size==0)
            return false;
        tail=(tail-1)%capacity;
        if(tail<0)
            tail+=capacity;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(size==0)
            return -1;
        return v[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(size==0)
            return -1;
        return v[tail];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(size==0)
            return true;
        else
            return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(size==capacity)
            return true;
        else
            return false;
    }
};

//Solution 3
class MyCircularDeque {
private:
    vector<int> deque;
    int max_size;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        max_size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(deque.size() == max_size)
            return false;
        deque.insert(deque.begin(), value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(deque.size() == max_size)
            return false;
        deque.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(deque.size() == 0)
            return false;
        deque.erase(deque.begin());
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(deque.size() == 0)
            return false;
        deque.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(deque.size() == 0)
            return -1;
        return deque[0];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(deque.size() == 0)
            return -1;
        int i = deque.size() - 1;
        return deque[i];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(deque.size() == 0)
            return true;
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(deque.size() == max_size)
            return true;
        return false;
    }
};
