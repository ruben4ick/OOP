#include "IDoubleList.h"   // Developed by Ruban on 17.04.2024

template <typename T>
class CyclicDoubleList : public IDoubleList<T> {
public:
    class BadCyclicDoubleList;
    CyclicDoubleList();
    ~CyclicDoubleList();

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
    _tail = nullptr; 
    _size = 0;
}

template<typename T>
void CyclicDoubleList<T>::insert_front(const T& value) {
    Node* newNode = new Node{ value, nullptr, nullptr };
    if (!_head) {
        newNode->_next = newNode;
        newNode->_prev = newNode;
        _head = newNode;
        _tail = newNode; 
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
void CyclicDoubleList<T>::insert_back(const T& value) {
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
    if (empty()) throw BadCyclicDoubleList("BadCyclicDoubleList: CyclicDoubleList is empty");
    if (!_head)
        return;
    Node* temp = _head;
    _head->_next->_prev = _head->_prev;
    _head->_prev->_next = _head->_next;
    _head = _head->_next;
    delete temp;
    _size--;
    if (_size == 0) {
        _tail = nullptr;
        _head = nullptr; 
    }
}

template<typename T>
void CyclicDoubleList<T>::pop_back() {
    if (empty()) throw BadCyclicDoubleList("BadCyclicDoubleList: CyclicDoubleList is empty");
    if (!_head)
        return;
    Node* temp = _tail;
    _tail = _tail->_prev; 
    _tail->_next = _head; 
    _head->_prev = _tail; 
    delete temp;
    _size--;
    if (_size == 0) {
        _head = nullptr;
        _tail = nullptr;
    }
}

template<typename T>
const T& CyclicDoubleList<T>::front() const {
    if (empty()) throw BadCyclicDoubleList("BadCyclicDoubleList: CyclicDoubleList is empty");
    return _head->_value;
}

template<typename T>
const T& CyclicDoubleList<T>::back() const {
    if (empty()) throw BadCyclicDoubleList("BadCyclicDoubleList: CyclicDoubleList is empty");
    return _tail->_value;
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
class  CyclicDoubleList<T>::BadCyclicDoubleList
{
private:
    string _message;

public:
    BadCyclicDoubleList(const string problem = "") : _message(problem)
    {
    }

    ~BadCyclicDoubleList()
    {
    }

    inline void diagnose() const
    {
        cerr << _message << endl;
    }
};

template <typename T>
class CyclicDoubleList<T>::Iterator {
public:
    mutable size_t _steps;
    Iterator(typename CyclicDoubleList<T>::Node* current) : _current(current), _start(current), _steps(0) {}
    void start() {
        _current = _start;
        _steps = 0;
    }
    bool stop() const {
        return _steps > 0 && _current == _start;
    }
    const Iterator& operator++() const {
        _current = _current->_next;
        ++_steps;
        return *this;
    }
    const T& operator*() const { return _current->_value; }

private:
    typename mutable CyclicDoubleList<T>::Node* _current;
    typename CyclicDoubleList<T>::Node* _start;
};


