#include "IDoubleList.h"   // Developed by Ruban on 17.04.2024

template <typename T>
class CyclicDoubleList : public IDoubleList<T> {
public:
    CyclicDoubleList();
    ~CyclicDoubleList();

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
    struct Node {
        T _value;
        Node* _next;
        Node* _prev;
    };

    size_t _size;
    Node* _head;
    Node* _tail;
};

template<typename T>
CyclicDoubleList<T>::CyclicDoubleList() : _size(0), _head(nullptr), _tail(nullptr) {}

template<typename T>
CyclicDoubleList<T>::~CyclicDoubleList() {
    Node* current = _head;
    if (current) {
        do {
            Node* next = current->_next;
            delete current;
            current = next;
        } while (current != _head);
    }
    _head = nullptr;
    _tail = nullptr; // ќчищенн€ вказ≥вника на останн≥й елемент
    _size = 0;
}

template<typename T>
void CyclicDoubleList<T>::push_front(const T& value) {
    Node* newNode = new Node{ value, nullptr, nullptr };
    if (!_head) {
        newNode->_next = newNode;
        newNode->_prev = newNode;
        _head = newNode;
        _tail = newNode; // якщо список був порожн≥й, то обидва вказ≥вники вказують на новий елемент
    }
    else {
        newNode->_next = _head;
        newNode->_prev = _head->_prev;
        _head->_prev->_next = newNode;
        _head->_prev = newNode;
        _head = newNode;
    }
    _size++;
}

template<typename T>
void CyclicDoubleList<T>::push_back(const T& value) {
    Node* newNode = new Node{ value, nullptr, nullptr };
    if (!_head) {
        newNode->_next = newNode;
        newNode->_prev = newNode;
        _head = newNode;
        _tail = newNode; 
    }
    else {
        newNode->_next = _head;
        newNode->_prev = _tail;
        _head->_prev = newNode;
        _tail->_next = newNode;
        _tail = newNode; 
    }
    _size++;
}

template<typename T>
void CyclicDoubleList<T>::pop_front() {
    if (!_head)
        return;
    Node* temp = _head;
    _head->_next->_prev = _head->_prev;
    _head->_prev->_next = _head->_next;
    _head = _head->_next;
    delete temp;
    _size--;
    if (_size == 0) 
        _tail = nullptr;
}

template<typename T>
void CyclicDoubleList<T>::pop_back() {
    if (!_head)
        return;
    Node* temp = _tail;
    _tail->_prev->_next = _head;
    _head->_prev = _tail->_prev;
    delete temp;
    _size--;
    if (_size == 0) 
        _head = nullptr;
}

template<typename T>
const T& CyclicDoubleList<T>::front() const {
    if (_head) {
        return _head->_value;
    }
    else {
        throw std::out_of_range("List is empty");
    }
}

template<typename T>
const T& CyclicDoubleList<T>::back() const {
    if (_tail) {
        return _tail->_value;
    }
    else {
        throw std::out_of_range("List is empty");
    }
}


template<typename T>
size_t CyclicDoubleList<T>::size() const {
    return _size;
}

template<typename T>
bool CyclicDoubleList<T>::empty() const {
    return _size == 0;
}

template<typename T>
void CyclicDoubleList<T>::print() const {
    if (!_head)
        return;
    Node* current = _head;
    do {
        std::cout << current->_value << " ";
        current = current->_next;
    } while (current != _head);
    std::cout << std::endl;
}

template <typename T>
class CyclicDoubleList<T>::Iterator {
public:
    Iterator(typename CyclicDoubleList<T>::Node* current) : _current(current), _start(current) {}
    void start() {
        _current = _start;
    }
    bool stop() const {
        return _current == front();
    }
    const Iterator& operator++() const {
        _current = _current->_next; return *this;
    }
    const T& operator*() const { return _current->_value; }

private:
    typename mutable CyclicDoubleList<T>::Node* _current;
    typename CyclicDoubleList<T>::Node* _start;
};
