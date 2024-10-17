
template <typename T>
class DoublyNode
{
public:
	T data;
	DoublyNode<T>* prev;
	DoublyNode<T>* next;
	DoublyNode(T value=0)
	{
		data = value;
		prev = next = nullptr;
	}
};