#include "IDoubleList.h"   // Developed by Ruban on 17.04.2024

template <typename T>
class DoubleList : public IDoubleList<T>
{
public:
	DoubleList();
	~DoubleList();
	void push_front(const T& value);
	void push_back(const T& value);
	void pop_front();
	void pop_back();
	const T& front() const;
	const T& back() const;
	size_t size() const;
	bool empty() const;
	void print() const;

	class Iterator;
	Iterator attach() const { return Iterator(_head); }

private:
	struct Node
	{
		T _value;
		Node* _next;
		Node* _prev;
	};

	size_t _size;
	Node* _head;
	Node* _tail;
};

template<typename T>
DoubleList<T>::DoubleList() : _size(0), _head(nullptr), _tail(nullptr) {}

template<typename T>
DoubleList<T>::~DoubleList() {
	while (_head) {
		Node* temp = _head;
		_head = _head->_next;
		delete temp;
	}
}

template<typename T>
void DoubleList<T>::push_front(const T& value) {
	Node* newNode = new Node{ value, nullptr, nullptr };
	if (!_head) {
		_head = newNode;
		_tail = newNode;
	}
	else {
		newNode->_next = _head;
		_head->_prev = newNode;
		_head = newNode;
	}
	_size++;
}

template<typename T>
void DoubleList<T>::push_back(const T& value) {
	Node* newNode = new Node{ value, nullptr, nullptr };
	if (!_tail) {
		_head = newNode;
		_tail = newNode;
	}
	else {
		newNode->_prev = _tail;
		_tail->_next = newNode;
		_tail = newNode;
	}
	_size++;
}

template<typename T>
void DoubleList<T>::pop_front() {
	if (!_head)
		return;
	Node* temp = _head;
	_head = _head->_next;
	if (_head)
		_head->_prev = nullptr;
	else
		_tail = nullptr;
	delete temp;
	_size--;
}

template<typename T>
void DoubleList<T>::pop_back() {
	if (!_tail)
		return;
	Node* temp = _tail;
	_tail = _tail->_prev;
	if (_tail)
		_tail->_next = nullptr;
	else
		_head = nullptr;
	delete temp;
	_size--;
}

template<typename T>
const T& DoubleList<T>::front() const
{
	if (_head) {
		return _head->_value;
	}
	else {
		throw std::out_of_range("List is empty"); 
	}
}

template<typename T>
const T& DoubleList<T>::back() const
{
	if (_tail) {
		return _tail->_value;
	}
	else {
		throw std::out_of_range("List is empty"); 
	}
}

template<typename T>
size_t DoubleList<T>::size() const {
	return _size;
}

template<typename T>
bool DoubleList<T>::empty() const {
	return _size == 0;
}

template<typename T>
void DoubleList<T>::print() const {
	Node* current = _head;
	while (current) {
		std::cout << current->_value << " ";
		current = current->_next;
	}
	std::cout << std::endl;
}

template <typename T>
class DoubleList<T>::Iterator {
public:
	Iterator(typename DoubleList<T>::Node* current) : _current(current), _start(current) {}
	void start() {
		_current = _start;
	}
	bool stop() const {
		return _current == 0;
	}
	const Iterator& operator++() const {
		_current = _current->_next; return *this;
	}
	const T& operator*() const { return _current->_value; }

private:
	typename mutable DoubleList<T>::Node* _current;
	typename DoubleList<T>::Node* _start;
};


template <typename Iter, typename T>
bool find(Iter& it, const T& elem)
{
	while (!it.stop())
	{
		if (elem == *it)
			return true;
		++it;
	}
	return false;
}



template <typename T, class Itor>
ostream& operator<<(ostream& os, const Itor& itor)
{
	while (!itor.stop())
	{
		os << *itor << ' ';
		++itor;
	}
return os << std::endl;
}
