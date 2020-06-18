#include "LinkedList.h"

// public

template <typename T>
DS::LinkedList<T>::LinkedList(T firstData)
{
	first = new Node(firstdata);
	first->prev = first->next = first;
	count = 1;
}

template <typename T>
DS::LinkedList<T>::~LinkedList()
{
	Node *ptr = start;
	Node *newPtr = ptr->next;
	delete ptr;
	ptr = newPtr;

	for (size_t i = 1; i < count; i++)
	{
		newPtr = ptr->next;
		delete ptr;
		ptr = newPtr;
	}
}

template <typename T>
bool DS::LinkedList<T>::Insert(T data, size_t index)
{
	Node *finded = &FindNode(index);

	if (finded == nullptr)
		return false;

	Node *newNode = new Node(data);
	newNode->prev = finded->prev;
	newNode->next = finded;
	newNode->prev->next = newNode;
	newNode->next->prev = newNode;

	count++;
}

template <typename T>
bool DS::LinkedList<T>::Delete(T data, size_t index)
{
	Node *finded = &FindNode(index);

	if (finded == nullptr)
		return false;

	finded->prev->next = finded->next;
	finded->next->prev = finded->prev;
	delete finded;

	count--;
}

template <typename T>
inline void DS::LinkedList<T>::PushFront(T data)
{
	Insert(0);
}

template <typename T>
inline void DS::LinkedList<T>::PushBack(T data)
{
	PushFront(data);
	first = *GetLast();
}

// private

template <typename T>
inline DS::LinkedList<T>::Node **DS::LinkedList<T>::GetLast()
{
	return &(first.prev);
}

template <typename T>
DS::LinkedList<T>::Node **DS::LinkedList<T>::FindNode(size_t index)
{
	// TODO: 한번 찾은 값을 저장해놓을 수 있도록 하거나 자동으로 테이블에 저장해두고 재사용
	if (index > size - 1)
		return nullptr;
	if (index == 0)
		return first;

	Node *result = first;
	for (size_t i = 1; i <= index; i++)
		result = result->next;

	return &result;
}

template <typename T>
DS::LinkedList<T>::Node::Node(const T &data)
{
	data = data;
	this.prev = this.next = nullptr;
}