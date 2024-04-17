#include "IDoubleList.h"   // Developed by Ruban on 17.04.2024

template <typename T>
class DoubleList : public IDoubleList<T>
{
public:
	class BadDoubleList;
	DoubleList();
	~DoubleList();
	void insert_front(const T& value);
	void insert_back(const T& value);
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
void DoubleList<T>::insert_front(const T& value) {
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
void DoubleList<T>::insert_back(const T& value) {
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
	if (empty()) throw BadDoubleList("BadDoubleList: DoubleList is empty");
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
	if (empty()) throw BadDoubleList("BadDoubleList: DoubleList is empty");
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
	if (empty()) throw BadDoubleList("BadDoubleList: DoubleList is empty");
	return _head->_value;
}

template<typename T>
const T& DoubleList<T>::back() const
{
	if (empty()) throw BadDoubleList("BadDoubleList: DoubleList is empty");
	return _tail->_value;
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
class  DoubleList<T>::BadDoubleList
{
private:
	string _message;

public:
	BadDoubleList(const string problem = "") : _message(problem)
	{
	}

	~BadDoubleList()
	{
	}

	inline void diagnose() const
	{
		cerr << _message << endl;
	}
};

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
	typename mutable DoubleList<T>::Node* _start;
};
