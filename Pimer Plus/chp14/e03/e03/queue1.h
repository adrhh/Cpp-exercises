#ifndef QUEUE_H_
#define QUEUE_H_

template <typename T>
class Queue
{
private:
	enum { QSIZE = 10 };
	struct Node{T item; Node * next;};
	Node* front;
	Node* rear;
	int items;
	const int qsize;
public:
	Queue(int n = QSIZE);
	~Queue();
	bool isempty() const { return items == 0; }
	bool isfull() const { return items == qsize; }
	bool enqueue(const T& item);
	bool dequeue(T& item);
};
#endif //!QUEUE_H_
