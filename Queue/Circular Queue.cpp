class CircularQueue
{
	private:
		vector<int> data;
		int size, cnt, front, rear;
		
	public:
		CircularQueue(int k)
		{
			size = k;
			front =0;
			rear = -1;
			cnt = 0;
		}
		bool enQueue(int val)
		{
			if(isFull()) return false;
			data[rear]  = val;
			rear = (rear + 1) % size;
			++cnt;
			return true;
		}
		bool deQueue()
		{
			if(isEmpty()) return false;
			front = (front + 1) % size;
			--cnt;
			return true;
		}
		int Front()
		{
			return (isEmpty() ? -1 : data[(front + 1) % size]);
		}
		int Rear()
		{
			return (isEmpty() ? -1 : data[(rear - 1 + size) % size]);
		}
		bool isEmpty()
		{
			return cnt == 0;
		}
		bool isFull()
		{
			return cnt == size;
		}
};