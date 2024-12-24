#include <iostream>
using namespace std;

template<typename T>
class Queue
{
private:
	T* data;
	int front;
	int rear;
	int capacity;
	int size;
public:
	Queue(int c)
	{
		capacity = c;
		front = 0;
		rear = -1;
		size = 0;
		data = new T[capacity];
	}
	~Queue()
	{
		delete[] data;
	}
	bool IsEmpty()
	{
		return size == 0;
	}
	bool IsFull()
	{
		return size == capacity;
	}
	void Enqueue(T val)
	{
		rear = (rear + 1) % capacity;
		data[rear] = val;
		size++;
	}
	T Dequeue()
	{
		T val = data[front];
		front = (front + 1) % capacity;
		size--;
		return val;
	}
	void Show()
	{
		cout << "Elements." << endl;
		for (int i = 0; i < size; i++)
		{
			cout << data[(front + i) % capacity] << " ";
		}
		cout << endl;
	}

};
int main()
{
	Queue<int> queue(5);
	queue.Enqueue(13);
	queue.Enqueue(23);
	queue.Enqueue(33);
	queue.Show();
	cout << "Dequeue: " << queue.Dequeue() << endl;
	queue.Show();
	queue.Enqueue(43);
	queue.Enqueue(53);
	queue.Enqueue(63);
	queue.Show();
	return 0;
}