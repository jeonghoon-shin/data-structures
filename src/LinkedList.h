#include <iostream>

namespace DS
{
	template <typename T>
	class LinkedList
	{
	public:
		LinkedList(T firstData);
		~LinkedList();

		bool Insert(T data, size_t index);
		bool Delete(T data, size_t index);
		inline void PushFront(T data);
		inline void PushBack(T data);

	private:
		struct Node
		{
			Node(const T &data);
			T data;
			T *prev, next;
		};

		inline Node **GetLast();
		Node **FindNode(size_t index);

		Node *first;
		size_t count;
	};
} // namespace DS
