#ifndef STACK_H_
#define STACK_H_

template <class T>
class ListNode
{
public:
	T value;
	ListNode* next;
};

template <class T>
class ForwardList
{
private:
	ListNode<T>* head;
	int size;
public:
	int getSize() const { return size; }
	ForwardList() : head(nullptr), size(0) {};
	bool isEmpty() const
	{
		if (size == 0)
			return true;
		else 
			return false; 
	}
	T pop_back()
	{
		if (!isEmpty())
		{
			ListNode<T>* actual = head;
			ListNode<T>* prev = actual;
			ListNode<T>* prev_prev = prev;
			T retVal;
			while (actual != nullptr)
			{
				prev_prev = prev;
				prev = actual;
				actual = actual->next;
			}
			retVal = prev->value;
			delete prev;
			prev_prev->next = nullptr;
			size--;

			return retVal;
		}
	}
	void push_back(T value)
	{
		ListNode<T>* newNode = new ListNode<T>{ value, nullptr };
		if (isEmpty())
			head = newNode;
		else
		{
			ListNode<T>* actual = head;
			ListNode<T>* prev = actual;
			while (actual != nullptr)
			{
				prev = actual;
				actual = actual->next;
			}
			prev->next = newNode;
		}
		size++;
	}
};

template <class T>
class Stack
{
private:
	ForwardList<T> fList;
public:
	bool isEmpty() const { return fList.isEmpty(); }
	T pop() { return fList.pop_back(); }
	void push(T value) { fList.push_back(value); };
	int getSize() const { return fList.getSize(); }
};

#endif // !STACK_H_