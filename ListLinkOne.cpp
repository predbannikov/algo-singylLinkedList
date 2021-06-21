// ListLinkOne.cpp : Defines the entry point for the application.
//
#include <iostream>

template <typename T>
class List {
public:
	List()  ;
	~List() { this->clear();  };
	void push_back(T data);
	T& operator[](const size_t index);
	size_t getSize() { return size; }
	void pop_frond();
	void push_frond(T data);
	void insert(T data, size_t index);
	void removeAt(size_t index);
	void pop_back();
	void clear();
private:
	template <typename T>
	class Node {
	public:
		T data;
		Node* pNext;
		Node(T data = T(), Node* next = nullptr) {
			this->data = data;
			pNext = next;
		}
	};
	Node<T>* pHead;
	size_t size;
};


int main()
{
	setlocale(LC_ALL, "ru");

	List<int32_t> list;
	list.push_back(5);
	list.push_back(7);
	list.push_back(22);
	list.push_back(25);

	auto print = [&list]() {
		for (size_t i = 0; i < list.getSize(); i++) {
			std::cout << list[i] << " ";
		}
	};
	

	std::cout << "Fore each items: " << std::endl;
	print();

	std::cout << "\ncall pop_front: " << std::endl;
	list.pop_frond();
	print();
	std::cout << "\ncall insert 1: " << std::endl;
	list.insert(99, 1);
	print();
	std::cout << "\ncall removeAt 1: " << std::endl;
	list.removeAt(1);
	print();
	std::cout << "\ncall pop_back: " << std::endl;
	list.pop_back();
	print();
	std::cout << "\nКоличество элементов = " << list.getSize() << std::endl;
	return 0;
}

template<typename T>
List<T>::List() : size(0), pHead(nullptr)
{
}

template<typename T>
void List<T>::push_back(T data)
{
	if (this->pHead == nullptr) {
		this->pHead = new Node<T>(data);
	} else {
		Node<T>* current = this->pHead;
		while (current->pNext != nullptr) 
			current = current->pNext;
		
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
T& List<T>::operator[](const size_t index)
{
	size_t curCounter = 0;
	Node<T>* current = this->pHead;
	while (current->pNext != nullptr) {
		if (curCounter == index)
			break;
		curCounter++;
		current = current->pNext;
	}
	return current->data;
}

template<typename T>
void List<T>::pop_frond()
{
	if (pHead != nullptr) {
		Node<T>* tmp = this->pHead;
		if (pHead->pNext != nullptr) {
			this->pHead = this->pHead->pNext;
		}
  		delete tmp;

	}
	size--;
}

template<typename T>
void List<T>::push_frond(T data)
{
	pHead = new Node<T>(data, pHead);
	size++;
}

template<typename T>
void List<T>::insert(T data, size_t index)
{
	if (index == 0) {
		push_frond(data);
	} else {
		Node<T>* previoues = pHead;
		size_t counter = 0;
		while (previoues->pNext != nullptr) {
			if (counter == index - 1) {
				break;
			}
			counter++;
			previoues = previoues->pNext;
		}
		if (counter == index - 1) {
			previoues->pNext = new Node<T>(data, previoues->pNext);
			size++;
		} else {
			push_back(data);
		}

	}
}

template<typename T>
void List<T>::removeAt(size_t index)
{
	if (index > size)
		return;
	if (index == 0) {
		pop_frond();
		return;
	}
	Node<T>* current = pHead;
	for (size_t i = 0; i < index - 1; i++) {
		current = current->pNext;
	}
	Node<T>* toDelete = current->pNext;
	current->pNext = toDelete->pNext;
	delete toDelete;
	size--;

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(size-1);
}

template<typename T>
void List<T>::clear()
{
	while (size > 0) {
		pop_frond();
	}
}


