#include<iostream>
using namespace std;
template<typename T>

template <typename T>

class Node
{
public:
	T data;
	Node<T>* next;
	Node(T val = 0):data(val),next(nullptr){}
};
class CircularLinkedList
{
	Node<T>* head;
public:
	CircularLinkedList() :head(nullptr) {}
	CircularLinkedList(CircularLinkedList<T>& list)
	{
		if (list.head == nullptr){ head = nullptr ; return ;}

		head = new Node<T>(list.head->data);
		Node<T>* sourceItr = list.head->next;
		Node<T>* destItr = head;
		while (sourceItr != list.head)
		{
			destItr->next = new Node<T>(sourceItr->data);
			destItr = destItr->next;
			sourceItr = sourceItr->next;
		}
		destItr->next = head;
	}

	void insertAtHead(T value)
	{
		if (!head) { head = new Node<T>(value); head->next = head; return; }
		Node<T>* temp = new Node<T>(value);
		Node<T>* itr = head;
		while (itr->next != head)
			itr = itr->next;
		temp->next = head;
		head = temp;
		itr->next = head;
	}
	void insertAtTail(T value)
	{
		if(!head){ head = new Node<T>(value); head->next = head; return; }
		Node<T>* itr = head;
		while (itr->next != head)
			itr = itr->next;
		itr->next = new Node<T>(value);
		itr->next->next = head;
	}
	int getLength()
	{
		if (!head) { return 0; }
		int i = 1;
		Node<T>* itr = head;
		while (itr->next != head) { itr = itr->next; i++; }
		return i;
	}
	void display()
	{
		if (head)
		{
			Node<T>* itr = head;
			do{ cout << itr->data << '\n';itr = itr->next;}while (itr != head);
		}
	}
	bool deleteAtHead()
	{
		if (head)
		{
			if (head->next == head) { Node<T>* temp = head; head = nullptr; delete temp; return true; }
			Node<T>* itr = head;
			while (itr->next != head)
				itr = itr->next;
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			itr->next = head;
			return true;
		}
		return false;
	}

	bool deleteAtTail()
	{
		if (head)
		{
			if (head->next == head) { deleteAtHead(); return true; }
			else
			{
				Node <T>* itr = head;
				Node<T>* prev = itr;
				while (itr->next != head) { prev = itr; itr = itr->next; }
				prev->next = head;
				delete itr;
				return true;
			}
		}
		return false;
	}

	Node<T>* search(T val)
	{
		if (head)
		{
			Node<T>* itr = head;
			while (itr->next != head)
			{
				if (itr->data == val)
					return itr;
				itr = itr->next;
			}
			if (itr->data == val)
				return itr;
			else
				return nullptr;
		}
		return nullptr;
	}

	bool insertAfter(T value , T key)
	{
		Node<T>* checker = search(key);
		if (checker)
		{
			Node<T>* toSet = checker->next; checker->next = new Node<T>(value); checker->next->next = toSet; return true;
		}
		return false;
	}

	bool insertBefore(T value, T key)
	{
		Node<T>* checker = search(key);
		if (checker)
		{
			if (checker == head){insertAtHead(value); return true;}
			Node<T>* itr = head;
			Node<T>* prev = head;
			while (itr != checker){ prev = itr; itr = itr->next;}
			prev->next = new Node<T>(value);
			prev->next->next = itr;
			return true;
		}
		return false;
	}

	bool deleteBefore(T value)
	{
		Node<T>* checker = search(value);
		if (checker)
		{
			if (checker == head) { return false; }
			if (checker == head->next) { deleteAtHead(); return true; }
			Node<T>* itr = head;
			Node<T>* prev = itr;
			Node<T>* temp = prev;
			while (itr->data != value){temp = prev;prev = itr;itr = itr->next;}
			delete prev;
			temp->next = itr;
			return true;
		}
		return false;
	}
	~CircularLinkedList()
	{
		if (head != nullptr && (getLength() > 0))
		{
			int length = getLength();
			while (length > 0) { deleteAtTail(); length--; }
		}
	}
};
